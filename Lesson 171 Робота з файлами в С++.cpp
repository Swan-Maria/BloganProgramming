// 1. Поняття потоків вводу / виводу в C++
// 2. Ієрархія потоків вводу / виводу в C++
// 3. Файл fstream
// 4. Як поламати потік ?
// 5. Режими відкриття файлу
// 6. Позиція у файлі та EOF
// 7. Як зчитати текст з файлу ?
// 8. Як записати текст у файл ?
// 9. Як записати НЕ текст у файл ?
// 10. Як зчитати НЕ текст з файлу ?
// 11. Як закрити файловий потік ?
// 12. Як дізнатися позицію файлу та змінити її ?

#include <ios>
#include <ostream>
#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    std::cout << "Hello World" << std::endl;

    /*
    -------------------------- Ієрархія потоків вводу / виводу в C++ --------------------------

    Є такий файл ios. В ньому є клас ios_base. В ньому знаходяться основні 
    методи і константи, які мають підтримувати всі потоки вводу/виводу. 
    Наприклад тут ви можете зустріти маніпулятори boolalpha, dec, 
    defaultfloat, fixed і інші.

    Також ви можете зустріти сутність std::ios, яка являється псевдонімом 
    до std::basic_ios<char, char_traits<char>>.

    Йдемо далі.

    Наступний файл ostream (output stream). В ньому уже знаходиться 
    клас basic_ostream. Цей клас наслідується від класу ios, а отже має
    всі ті самі маніпулятори і методи на подобі clear, fill і інших. Але 
    цей клас відповідає тепер за конкретний потік ВИВОДУ. Тобто його треба 
    використовувати, щоб ВИВОДИТИ інформацію звідкись. Цей клас уже 
    добавляє свої маніпулятори, такі як endl, ends та flush, а також 
    безліч перезавантажень для оператора <<.

    Наступний файл istream (input stream). В ньому уже знаходиться клас 
    basic_istream. Тут ситуація аналогічна: він також наслідується від 
    класу ios, а отже має всі ті самі маніпулятори і методи. Але цей клас 
    відповідає тепер за конкретний потік ВВОДУ. Тобто його треба 
    використовувати, щоб ВВОДИТИ інформацію кудись. Цей клас уже добавляє 
    свої маніпулятори, такі як ws, а також безліч перевантажень для оператора >>.

    Пам'ятаєте std::cin? Так от, cin - це глобальний об'єкт (де він створюється, 
    ми поговоримо пізніше) цього класу. А точніше він створюється завдяки 
    псевдоніму std::istream = basic_istream<char, char_traits<char>>.

    Також у файлі istream знаходиться клас basic_iostream, який наслідується 
    від двох класів basic_istream та basic_ostream. Ну і очевидно, що він в собі 
    комбінує ввід і вивід інформації.

    А тепер поговоримо про місце, де створюються глобальні об'єкти std::cin і 
    std::cout. Це файл iostream (який ви підключаєте). Він підключає в себе всі 
    попередні файли а також безліч інших. Саме тому ми його і підключаємо постійно, 
    якщо хочемо працювати з вводом/виводом інформації в консолі.

    В цьому файлі ви знайдете інші об'єкти, такі як std::cerr і std::clog. 
    Чим вони відрізняються від std::cout?

    1. std::cout - це стандартний потік виводу, який використовується для нормального
    виводу інформації у програмі. Він буферизується, що означає, що дані зберігаються
    в пам'яті перед їх надсиланням в консоль/термінал. Це може покращити продуктивність,
    оскільки кілька операторів виводу можна об'єднати в одну операцію.

    2. std::cerr - це стандартний потік виводу помилок, який використовується для 
    овідомлення про помилки та діагностичного виведення. Він не буферизується, що 
    означає, що дані надсилаються безпосередньо на консоль або термінал, як тільки 
    вони записуються. Це гарантує, що повідомлення про помилки відображаються миттєво 
    та не втрачаються в разі збою програми.

    3. std::clog - це стандартний потік логування, який використовується для реєстрації 
    повідомлень. Він буферизується як std::cout, але зазвичай використовується для 
    реєстрації інформації, яка не є критичною для роботи програми.

    ---------------------------------------------------------------------------------------------
    
    Переходимо до головної теми цього відео. В ієрархії потоків вводу/виводу є файл 
    fstream (file stream). В цьому файлі знаходяться зразу три класи:
    1. ifstream (input file stream) – клас, який відповідає за зчитування даних з файлу.
    2. ofstream (output file stream) – клас, який відповідає за запис даних у файл.
    3. fstream (file stream) – клас, який є об'єднанням двох класів ifstream та ofstream.

    Клас ifstream наслідується від basic_istream, а отже має той самий інтерфейс + декілька 
    нових методів для роботи конкретно з файлами (наприклад open, is_open).

    Аналогічна ситуація з класом ofstream. Він наслідується від basic_ostream.

    Клас fstream наслідується від класу basic_iostream і комбінує в собі ввід та вивід 
    інформації з файлу чи у файл.

    */

    /*
    --------------------------------------- Як поламати потік? ------------------------------------- 
    В кожному класі з нашої ієрархії є поле, яке називається _Mystate. Воно має тип int і відповідає 
    за стан потоку. Стан може бути добрим (полагодженим / з яким можна працювати) або поганим (який 
    треба або полагодити або перестати працювати). В ньому записується одне з 4 можливих значень:
    1. std::ios::goodbit - відповідає за те, що потік працює нормально. Встановлюється за замовчуванням 
                            при створенні потоку.
    2. std::ios::eofbit - встановлюється тоді, коли при зчитуванні даних з потоку ми зустріли кінець
                            файлу (EOF - End Of File).
    3. std::ios::failbit - встановлюється тоді, коли відбулася помилка, яку можна виправити.
                            Наприклад, коли потік не може читати чи записувати дані через тимчасовий 
                            збій в мережі, або дані не відповідають очікуваному формату.
    4. std::ios::badbit - встановлюється тоді, коли відбулася помилка, яку не можна виправити. 
                            Наприклад, коли потік не може зчитувати або записувати дані через апаратний 
                            збій чи потік неочікувано закрився.

    Щоб перевірити стан потоку, існують 4 методи: good(), eof(), fail(), bad(). Вони повертають true, 
    якщо встановлений один з 4 бітів.

        */

        // Ось приклад на перевірку цих бітів:
        {
            std::cout << "Enter a number: ";
            int number;
            std::cin >> number;

            if (std::cin.good())
                std::cout << "Your number = " << number << std::endl;
            else
            {
                std::cout << "Oops. Something went wrong.\n";
                if (std::cin.bad())
                    std::cout << "cin.bad() == true.\n";
                if (std::cin.fail())
                    std::cout << "cin.fail() == true.\n";
                if (std::cin.eof())
                    std::cout << "cin.eof() == true.\n";
            }
        }

    // -------------------------------- Як полагодити потік? --------------------------------
    // 1. Якщо стан потоку має значення std::ios::eofbit, то в такому випадку потік дійшов до
    // кінця запису/зчитування і вам треба його закрити та заново відкрити. Робиться це методами 
    // close та open. Це відбувається зазвичай при роботі з файлами.

    // 2. Якщо стан потоку має значення std::ios::fail, то в такому випадку ви можете спочатку 
    // викликати метод clear(), який встановить стан потоку заново в значення std::ios::goodbit, 
    // а потім почистити потік методом ignore(), який витягне звідти символи, але не запише їх 
    // в потік (щоб він заново не поламався). Після цього можна продовжити роботу.

    // 3. Якщо стан потоку має значення std::ios::badbit, то в такому випадку ви
    // можете викликати метод clear(), але це не гарантує, що потік зможе спокійно
    // працювати далі, так як такий біт встановлюється у "невиправних" ситуаціях.
    // Тут рекомендується більше не працювати з потоком, а відкрити новий (або
    // закрити і відкрити цей).

    // Ось приклад полагодження потоку:
    {
        std::cout << "Enter a number: ";
        int number;
        std::cin >> number; // Q

        while (!std::cin.good() && std::cin.fail())
        {
            std::cin.clear();
            std::cout << "You entered incorrect value. Enter only one integer number.\n";
            std::cin.ignore(LLONG_MAX, '\n');
            std::cout << "Enter a number: ";
            std::cin >> number;
        }

    }

    std::ios::in;
    // -------------------------------- Режими відкриття файлу --------------------------------
    // 1. std::ios::in    - відкрити файл для читання. Якщо файлу не існує - потік "ламається".
    // 2. std::ios::out   - відкрити файл для запису. Якщо файл існує - його вміст очищається (можливо).
    //                      Якщо не існує - файл створюється.
    // 3. std::ios::app   - відкрити файл для запису в кінець. Якщо файлу не існує - файл створюється.
    // 4. std::ios::trunc - використовується з режимом out. Заставляє файл очиститися, якщо в ньому
    //                      щось було до відкриття.
    // 5. std::ios::ate   - використовується з іншими режимами. Переміщає вказівник зчитування в кінець
    //                      файлу.
    // 6. std::ios::binary - відкрити файл у бінарному режимі. Використовується з іншими режимами.

    // ------------------------------- Позиція у файлі та EOF -------------------------------
    // При роботі з файлами інструментами мови C++ все працює так само, як і з інструментами мови C:
    // При з'єднанні файлового потоку з файлом у файлі з'являється вказівник на конкретний елемент
    // у файлі. Будемо називати його позиція у файлі. Якщо ви відкрили файл для читання завдяки
    // режиму 1. std::ios::in, то позиція указує на нульовий елемент. Аналогічно з std::ios::out.
    // При зчитуванні/записі інформації у файл ця позиція переміщується завжди вперед, допоки не зустріне
    // спеціальний символ, який символізує кінець файлу. Він називається EOF (End Of File). Тому часто
    // при зчитуванні інформації з файлу треба писати код, в якому зчитування має відбуватися до цього символу.
    // Як дізнатися позицію у файлі та як її змінити, я розповім в кінці уроку.

    //----------------------------- Чотири способи зчитати текст із файлу---------------------------- -

    //  1. Посимвольно.
    {
        std::string filename = "MyTextFile.txt";
        std::ifstream fileStream(filename);

        if (!fileStream.is_open())
        {
            std::cerr << "Couldn't open the file. :( \n";
            return 1;
        }

        char character;
        while (fileStream.get(character))
        {
            std::cout << character;
        }

        if (fileStream.eof())
        {
            std::cout << "\n\nWe reached the end of the file.\n";
        }


    }
    //  2. Порядково.
    {
        std::string filename = "MyTextFile.txt";
        std::ifstream fileStream(filename);

        if (!fileStream.is_open())
        {
            std::cerr << "Couldn't open the file. :( \n";
            return 1;
        }

        std::string line;
        while (std::getline(fileStream, line, '\r'))
            std::cout << line;

        if (fileStream.eof())
            std::cout << "\n\nWe reached the end of the file.\n";
    }
    //  3. Побайтово. 
    {
        std::string filename = "MyTextFile.txt";
        std::ifstream fileStream(filename, std::ios::binary);

        if (!fileStream.is_open())
        {
            std::cerr << "Couldn't open the file. :( \n";
            return 1;
        }

        // Визначити кількість байтів у файлі:
        fileStream.seekg(0, std::ios::end);
        size_t fileSize = fileStream.tellg();
        fileStream.seekg(0, std::ios::beg);

        // Створити тимчасовий масив:
        size_t bufferLength = fileSize + 1;
        char* buffer = new char[bufferLength];
        fileStream.read(buffer, fileSize);
        buffer[fileSize] = '\0';
        
        // Перевірити, чи файл було повністю зчитано:
        if (fileStream.gcount() != fileSize)
        {
            std::cerr << "Error reading file. :( \n";
            return 1;
        }

        std::cout << buffer;

        delete[] buffer;


    }
    //  4. Завдяки перезавантаженому оператору >> так само, як ви це робите з std::cin.
    {
        std::string filename = "MyTextFile.txt";
        std::ifstream fileStream(filename, std::ios::binary);

        if (!fileStream.is_open())
        {
            std::cerr << "Couldn't open the file. :( \n";
            return 1;
        }

        std::string word;
        while (fileStream >> word) // обережно, пропускаються пробільні символи
            std::cout << word;
    }

    // ------------------------------ Як записати текст у файл? ------------------------------
    // Текст можна записати у файл трьома способами (по крайній мірі я знаю 3 способи):
    // 1. Посимвольно.
    {
        std::string filename = "MyTextFile1.txt";
        std::ofstream fileStream(filename);

        if (!fileStream.is_open())
        {
            std::cerr << "Couldn't open the file. :( \n";
            return 1;
        }

        std::cout << "Enter some text: ";
        std::string text;
        std::getline(std::cin, text);

        size_t textLength = text.length();
        for (size_t i = 0; i < textLength; i++)
        {
            fileStream.put(text[i]);
        }
    }
    // 2. Порядково завдяки перезавантаженому оператору << так само, як ви це робите з std::cout.
    {
        std::string filename = "MyTextFile2.txt";
        std::ofstream fileStream(filename);

        if (!fileStream.is_open())
        {
            std::cerr << "Couldn't open the file. :( \n";
            return 1;
        }

        std::string line1 = "Today is a good day!";
        std::string line2 = "Because I am recording a lesson!";

        fileStream << line1 << '\n' << line2 << '\n';
    }
    // 3. Побайтово.
    {
        std::string filename = "MyTextFile3.txt";
        std::ofstream fileStream(filename, std::ios::binary);

        if (!fileStream.is_open())
        {
            std::cerr << "Couldn't open the file. :( \n";
            return 1;
        }

        std::string line = "Some line of text.";
        fileStream.write(line.c_str(), line.length());
    }

    // ------------------------------------------------------ Як записати НЕ текст у файл ? ------------------------------------------------------
    {
        // Візьмемо декілька даних різних типів:
        int variable = 10;
        double array[3] = { 1.123, 2.456, 3.789 };

        class Point
        {
        private:
            float x;
            float y;

        public:
            Point(float x = 0, float y = 0)
                : x(x), y(y)
            {
            }

            float X() const { return x; }
            float Y() const { return y; }
        };

        Point myPoint(12.3f, 54.6f);

        std::vector<int> myVector = { 1, 2, 3, 4, 5 };

        // Всі вони записуються завдяки методу write. Все що треба зрозуміти – це
        // те, що цей метод записує дані в байтах, тобто йому треба відправляти адресу
        // типу char (так як розмір типу char відповідає за розмір одного байту).

        // Тому вам треба перетворювати ваші дані в адресу на цей тип і відправляти
        // цьому методу.

        // Спробуємо створити файл, в який запишемо всі ці дані, послідовно.

        std::string filename = "MyData.bin"; // бін я написав від балди, це ролі не грає.
        std::ofstream fileStream(filename, std::ios::binary);

        if (!fileStream.is_open())
        {
            std::cerr << "Couldn't open the file. :( \n";
            return 1;
        }

        fileStream.write(reinterpret_cast<const char*>(&variable), sizeof(variable));
        fileStream.write(reinterpret_cast<const char*>(&array), sizeof(double) * 3);

    }

    // ---------------------------- Як зчитати НЕ текст з файлу? ----------------------------
    // Щоб зчитати не текст із файлу, вам треба спочатку створити ці дані у вашій програмі:
    {
        int variable;
        double array[3];

        class Point
        {
        private:
            float x;
            float y;

        public:
            Point(float x = 0, float y = 0)
                : x(x), y(y)
            {}
            float X() const { return x; }
            float Y() const { return y; }
        };

        Point myPoint;

        std::vector<int> myVector(5);

        // А тепер завдяки методу read ми зчитуємо ці дані в такому ж порядку, як і записували.
        // Ви маєте знати цей порядок.
        std::string filename = "MyData.bin";
        std::ifstream fileStream(filename, std::ios::binary);

        if (!fileStream.is_open())
        {
            std::cerr << "Couldn't open the file. :( \n";
            return 1;
        }

        fileStream.read(reinterpret_cast<char*>(&variable), sizeof(variable));

        fileStream.read(reinterpret_cast<char*>(&array), sizeof(double) * 3);

        fileStream.read(reinterpret_cast<char*>(&myPoint), sizeof(Point));

        fileStream.read(reinterpret_cast<char*>(myVector.data()), sizeof(int)* myVector.size());

        std::cout << "variable = " << variable << std::endl;

        std::cout << "array = ";
        for (size_t i = 0; i < 3; i++)
        {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Point: [x = " << myPoint.X() << ", y = " << myPoint.Y() << "]\n";

        std::cout << "vector = ";
        for (size_t i = 0; i < myVector.size(); i++)
        {
            std::cout << myVector[i] << " ";
        }
        std::cout << std::endl;

    }

    // -------------------------------- Як закрити файловий потік? --------------------------------
    {
        // Якщо ви попрацювали з потоком і більше не плануєте з ним працювати до кінця його
        // області видимості (тобто поки об'єкт потоку не знищиться), ви можете закрити його.
        // Закрити означає відв'язати потік від файлу, щоб файлом могли користуватися інші потоки.
        // Для цього використовуйте метод close:

        // Відкрили потік:
        std::string filename = "SomeFile";
        std::ifstream fileStream(filename);

        // ... Попрацювали з потоком ...

        // Закрили потік:
        fileStream.close();

        // Також ви маєте знати, що класи std::ifstream, std::ofstream, та std::fstream
        // мають деструктор, який автоматично викликає метод close.
    }

    // ------------------------------ Як дізнатися позицію файлу та змінити її? ------------------------------
    {
        // Давайте спробуємо розв'язати якусь цікаву задачу:
        // Є файл Numbers.bin, в якому знаходиться невідома кількість чисел типу int.
        // Кількість цих чисел – це число, яке знаходиться на першому місці у файлі.
        // Ви маєте знайти у цьому масиві перше число 20 і замінити його на 40.
        // Інший вміст файлу міняти заборонено.

        // Як вирішувати цю задачу? Спочатку треба зчитати всю інформацію з нього:
        std::string filename = "Numbers.bin";
        std::ifstream fileStream(filename, std::ios::binary);
        if (!fileStream.is_open())
        {
            std::cerr << "Couldn't open the file. :( \n";
            return 1;
        }

        int size;
        fileStream.read(reinterpret_cast<char*>(&size), sizeof(int));

        std::vector<int> numbers(size);

        for (size_t i = 0; i < size; i++)
        {
            int number;
            fileStream.read(reinterpret_cast<char*>(&number), sizeof(int));
            numbers[i] = number;
        }

        fileStream.close();

        // Інформація отримана. Треба тепер знайти перше число 20.
        bool isNumberFound = false;
        size_t findIndex;
        for (size_t i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] == 20)
            {
                isNumberFound = true;
                findIndex = i;
                break;
            }
        }

        // Якщо число найдене – відкриваємо заново файл, тільки для запису
// але БЕЗ ВИДАЛЕННЯ інформації.
        if (isNumberFound)
        {
            std::ofstream fileStream(filename, std::ios::app | std::ios::binary);
            if (!fileStream.is_open())
            {
                std::cerr << "Couldn't open the file. :( \n";
                return 1;
            }
 
            // Я використав std::ios::app, щоб не очищати вміст файлу, але тепер
            // у мене позиція файлу знаходиться в кінці, а мені треба, щоб вона
            // була на початку. Для цього в хід вступають методи seekp, tellp та peek.

            // Метод peek() і tellp повертає теперішню позицію у файлі.
            // Метод seekg()/seekp приймає два параметри: місце, з якого треба відсунути
            // позицію, та кількість елементів, на які треба посунути позицію.
            // Ось декілька прикладів:

            {
                fileStream.seekp(std::ios::beg); // розмістити позицію на початок файлу.
                fileStream.seekp(std::ios::cur); // розмістити позицію туди, де знаходиться дана позиція.
                fileStream.seekp(std::ios::end); // розмістити позицію на кінець файлу.

                fileStream.seekp(std::ios::beg, 5); // розмістити позицію на 5 елементів справа від початку.
                fileStream.seekp(std::ios::cur, -3); // розмістити позицію на 3 елементи зліва від даної позиції.
                fileStream.seekp(std::ios::end, -10); // розмістити позицію на 10 елементів зліва від кінця файлу.
            }

            // Нам треба знайти місце елемента зі значенням 20. Щоб це зробити, нам треба задати позицію на початок файлу.
            // У нас уже є його індекс. Також ми знаємо, що всі елементи мають тип int, а також те, що перший елемент
            // пропустити, бо це розмір масиву. Тому пишемо наступний код:
            size_t value20Position = sizeof(int) + sizeof(int) * findIndex;
            fileStream.seekp(std::ios::beg, value20Position);
            int newNumber = 40;
            fileStream.write(reinterpret_cast<const char*>(&newNumber), sizeof(int));

            fileStream.close();

            // Bce.
        }

    }
    return 0;
}
