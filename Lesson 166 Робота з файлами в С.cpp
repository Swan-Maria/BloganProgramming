// 1. Як виглядають шляхи до файлів?
// 2. Як створити папку?
// 3. Як перейменувати папку?
// 4. Як видалити папку?
// 5. Як створити файл?
// 6. Як перейменувати файл?
// 7. Як видалити файл?
// 8. Що означають розширення файлів?
// 9. Поняття потоків вводу і виводу
// 10. Текстові і бінарні файли
// 11. Як закрити файл?
// 12. Вказівники позиції у файлі
// 13. Що таке EOF?
// 14. Як зчитати інформацію з файлу?
// 15. Як записати у файл інформацію?
// 16. Переміщення позиції файлових вказівників


// Подключение библиотек
#include <iostream>
#include <string>
#include <direct.h> // для _mkdir()

// Функция для отображения сообщений об ошибке
void ShowErrnoMessage()
{
    std::cout << "Error code: " << errno << std::endl;
    std::cout << "Message: ";
    if (errno == EEXIST)
        std::cout << "Folder already exists.\n";
    else if (errno == ENOENT)
        std::cout << "Path is incorrect.\n";
    std::cout << std::endl;
}

// Определение структуры
struct Person
{
    char name[50]{};
    int age;
};

// Операции с папками
void CreateFolder()
{
    const char* folder1Name = "MyFolder";
    const wchar_t* folder2Name = L"Моя папка";
    int creationResult;
    creationResult = _mkdir(folder1Name);
    if (creationResult != 0)
    {
        std::cout << "Error! Cloud not create folder.\n";
        ShowErrnoMessage();
    }
    creationResult = _wmkdir(folder2Name);
    if (creationResult !=  0)
    {
        std::cout << "Error! Cloud not create folder.\n";
        ShowErrnoMessage();
    }
}
void RenameFolder()
{
    const char* oldName = "Filder";
    const char* newName = "Folder";
    int renamingResult = rename(oldName, newName);
    if (renamingResult != 0)
        std::cout << "Folder could not been renamed.\n";
}
void DeleteFolder()
{
    const char* folderPath = "Empty";
    std::string removeCommand = "rmdir ";
    removeCommand += folderPath;
    int removingResult = system(removeCommand.c_str());
    if (removingResult != 0)
        std::cout << "Folder could not been removed.\n";
}

// Операции с файлами
void CreateFile()
{
    // Функція створення/відкриття файлів fopen:
    // Прототип:  FILE* fopen (const char* filename, const char* mode)
    // Параметри: filename - шлях до файлу разом з назвою та розширенням
    //            mode     - режим відкриття файлу
    // Повертаюче значення: вказівник на відкритий файл. nullptr  - файл не можливо відкрити/створити.
    // 
    // Замітка: для типу wchar_t існує функція _wfopen.
    // 
    // FILE - це структура, яка містить лише одне поле - вказівник на файл.
    // 
    // УВАГА: компілятор VS за замовчуванням не дозволяє використовувати функцію fopen,
    //        бо вважає її небезпечною. Він рекомендує використовувати натомість
    //        функцію fopen_s().
    //
    // Функція створення/відкриття файлів fopen_s:
    // Прототип:  errno_t fopen(FILE** stream, const char* filename, const char* mode)
    // Параметри: stream - адреса на вказівник типу File, до якого прив'яжеться файл
    //            filename - шлях до файлу разом з назвою та розширенням
    //            mode     - режим відкриття файлу
    // Повертаюче значення: 0 - файл успішно відкрито, значенння EINVAL в інших випадках..
    // 
    // Замітка: для типу wchar_t існує функція _wfopen_s.
    // 
    // Режими відкриття файлу:
    // "r"  - відкриває файл для читання. Якщо файла не існує чи його неможливо найти 
    //       повертається nullptr.
    // "w"  - відкриває пустий файл для запису. Якщо файл існує, то його вміст видаляється.
    // "a"  - відкриває файл для запису в його кінець. Створює файл, якщо його не існує.
    // "r+" - відкриває файл для читання і для запису. Файл має існувати.
    // "w+" - відкриває пустий файл для читання і для запису. Якщо файл існує, 
    //        то його вміст видаляється.
    // "a+" - відкриває файл для читання і для запису в його кінець. Створює файл, якщо його не існує.
    //
    // Варіанти відкриття через fopen:
    // FILE* file1;
    // file1 = fopen("sdgsdgh.txt", "r");
    // if (file1 == nullptr)
    //      std::cout << "File could not been opened.\n";
    // 
    // Варіанти відкриття через fopen_s:
    // FILE* file2;
    // errno_t openingResult = fopen_s(&file2,"123.txt", "w");
    // if (openingResult == 0)
    //      std::cout << "File could not been opened.\n";    
}
void RenameFile()
{
    const char* oldName = "OldFileName";
    const char* newName = "NewFileName";
    int renamingResult = rename(oldName, newName);
    if (renamingResult != 0)
        std::cout << "File could not been renamed.\n";
}
void DeleteFile()
{
    const char* filename = "MyFileForDelete.txt";
    int deletionResult = remove(filename);
    if (deletionResult != 0)
        std::cout << "Folder could not been removed.\n";
}
void CloseFile()
{
    // Відкрили файл і з'єднали з потоком
    const char* filename = "SomeFole.txt";
    FILE* file;
    fopen_s(&file, filename, "w");
    while (true)
    { }
    // -------------------
    // Працюювати з файлом
    // -------------------
    // Закрити файл, від'єднавши потік.
    fclose(file);
}

// Потоковые операции с файлами
void ReadFromFile()
{
    // Є декілька функцій для читання інформації з файлу:
    // 
    // 1. Прототип:             int fgetc(FILE*stream)
    //    Опис:                 читає і повертає наступний символ з потоку.
    //    Параметри:            stream - потік на файл.
    //    Повертаюче значення:  зчитаний символ, якщо вийшло зчитати.
    //                          Інакше EOF.
    // 
    // 2. Прототип:             char* fgets(char* strm int countm FILE* stream)
    //    Опис:                 читає максимум (count - 1) символів із потоку і збурігає
    //                          їх в масиві str. Зчитування зупиняється, якщо зустрічається 
    //                          символ \n або кінець файлу. Дописує нуль-символ в кінець
    //                          зчитаної послідовності.
    //    Параметри:            str     - масив, куди запишуться символи
    //                          count   - розмір маисву str
    //                          stream  - потік на файл.
    //    Повертаюче значення:  str, якщо успішно вдалося зчитати послідовність.
    //                          nullptr, якщо виникла проблема.
    // 
    // 3. Прототип:             size_t fread(void* buffer, size_t size, size_t count, FILE* stream)
    //    Опис:                 зчитує максимум count байтів у вказівник buffer із потоку stream
    //    Параметри:            buffer  - вказівник, куди запишуться байти
    //                          size    - розмір кожного елементу послідовності даних, які треба зчитати
    //                          count   - кількість байтів для зчитування. 
    //                          stream  - потік на файл
    //    Повертаюче значення:  кількість успішно зчитаних байтів.
 
    // Приклад виуористання fgetc:
    {
        const char* filename = "Text.txt";
        FILE* fileStream;
        fopen_s(&fileStream, filename, "r");
        if (fileStream == nullptr)
        {
            std::cout << "Could notopen the file.\n";
            return;
        }
        int character = fgetc(fileStream);
        while (character != EOF)
        {
            std::cout << static_cast<char>(character);
            character = fgetc(fileStream);
        }
        fclose(fileStream);
    }
    
    // Приклад виуористання fgets:
    {
        const char* filename = "Text.txt";
        FILE* fileStream;
        fopen_s(&fileStream, filename, "r");
        if (fileStream == nullptr)
        {
            std::cout << "Could not open the file.\n";
            return;
        }

        const size_t SIZE = 100;
        char string[SIZE]{};

        while (fgets(string, SIZE, fileStream) != nullptr)
        {
            std::cout << string;
        }

        fclose(fileStream);
    }
    // Приклад виуористання fread:
    {
        int intVariable = 10;
        const size_t SIZE = 3;
        char charArray[SIZE] = { 'A', 'B', 'C' };
        Person demian{ "Demian", 25 };

        // Спочатку запишемо дані у файл:
        /*FILE* fileStream{};
        const char* filename = "Data.bin";
        fopen_s(&fileStream, filename, "wb");
        if (fileStream != nullptr)
        {
            fwrite(&intVariable, sizeof(int), 1, fileStream);
            fwrite(charArray, sizeof(char), SIZE, fileStream);
            fwrite(&demian, sizeof(Person), 1, fileStream);
        }
        fclose(fileStream);*/

        // Зараз зміню дані, щоб потім довести, що інформація з файлу дійсно зчиталася.
        intVariable = 0;
        charArray[0] = '\0';
        demian.age = 0;
        demian.name[0] = '\0';

        // А тепер зчитаємо інформацію з файлу:
        FILE* fileStream;
        const char* filename = "Data.bin";
        fopen_s(&fileStream, filename, "wb");
        if (fileStream != nullptr)
        {
            fwrite(&intVariable, sizeof(int), 1, fileStream);
            fwrite(charArray, sizeof(char), SIZE, fileStream);
            fwrite(&demian, sizeof(Person), 1, fileStream);
        }
        fclose(fileStream);

        fopen_s(&fileStream, filename, "rb");
        if (fileStream == nullptr)
        {
            fread(&intVariable, sizeof(int), 1, fileStream);
            fread(charArray, sizeof(char), SIZE, fileStream);
            fread(&demian, sizeof(Person), 1, fileStream);
            fclose(fileStream);
        }

        // Перевіряємо, чи считалося добре.
        std::cout << "intVariable = " << intVariable << std::endl;

        std::cout << "charArray = [";
        for (size_t i = 0; i < SIZE; i++)
        {
            std::cout << charArray[i];
        }
        std::cout << "]\n";

        std::cout << "demian.name: " << demian.name << std::endl;
        std::cout << "demian.age: " << demian.age << std::endl;
    }
}
void WriteIntoFile()
{
    // Є декілька функцій для запису інформації у файл :
    // 
    // 1. Прототип:          int fputc(int ch, FILE * stream);
    //  Опис:                Записує символ ch в файловий потік stream
    //  Параметри:           ch      - символ
    //                       stream  - потік, зв'язаний з файлом
    //  Повертаюче значення: якщо символ успішно записався - повертає символ.
    //                       Інакше  - EOF.
    // 
    // 2. Прототип:          int fputs(const char* str, FILE * stream);
    //  Опис:                Записує рядок str в файловий потік stream
    //  Параметри:           str     - рядок
    //                       stream  - потік, зв'язаний з файлом
    //  Повертаюче значення: якщо рядок успішно записався - повертає ненульове значення.
    //                       Інакше  - EOF.
    // 
    // 3. Прототип:         size_t fwrite(const void* buffer, size_t size, size_t count, FILE * stream);
    //  Опис:               записує дані, на які вказує buffer, в файловий потік stream
    //  Параметри:          buffer - вказівник на дані, які треба записати
    //                      size - розмір кожного елементу даних, які треба записати
    //                      count - кількість елементів даних, які треба записати
    //                      stream - потік, зв'язаний з файлом
    // Повертаюче значення: Кількість об'єктів, які записалися успішно.
    //                      Якщо це значення менше за count - щось пішло не так.

    // Приклад використання функції fputc:
    {
        FILE* fileStream = nullptr;
        const char* filename = "Characters.txt";

        fopen_s(&fileStream, filename, "w");
        if (fileStream != nullptr)
        {
            fputc('!', fileStream);
            fputc('@', fileStream);
            fputc('#', fileStream);

            fclose(fileStream);
        }
    }

    // Приклад використання функції fputs:
    {
        FILE* fileStream = nullptr;
        const char* filename = "Strings.txt";

        fopen_s(&fileStream, filename, "w");
        if (fileStream != nullptr)
        {
            fputs("My name is ", fileStream);
            fputs("Demian\n", fileStream);
            fputs("And I am trying to put some strings into file", fileStream);

            fclose(fileStream);
        }
    }

    // Приклад використання функції fwrite:
    {
        FILE* fileStream = nullptr;
        const char* filename = "Numbers.bin";

        fopen_s(&fileStream, filename, "w");
        if (fileStream != nullptr)
        {
            const size_t SIZE = 4;
            int numbers[SIZE] = { 1, 2, 10, 20 };

            fwrite(numbers, sizeof(int), SIZE, fileStream);

            fclose(fileStream);
        }
    }

}

void FilePositioning()
{
    // Оскільки у файлі є вказівники на наступні символи для зчитування, то ми можемо
    // працювати з ними.Наприклад, коли ми використовуємо функції для читання чи запису,
    // то після проведених операцій ці функції переміщають ці вказівники далі.

    // Бувають ситуації, коли нам треба знати місцезнаходження цих вказівників або
    // коли нам треба перемістити їх назад чи вперед.

    // Для роботи з вказівниками є наступні функції :
    // 1. long ftell(FILE * stream)                         — повертає позицію файлового вказівника.
    // 2. int fseek(FILE * stream, long offset, int origin) — встановлює позицію файлового вказівника.
    // 3. int fgetpos(FILE * stream, fpos_t * pos)          — записує позицію файлового вказівника в pos.
    // 4. int fsetpos(FILE * stream, const fpos_t * pos)    — переміщує позицію файлового вказівника з pos.
    // 5. void rewind(FILE * stream)                        — вертає позицію файлового вказівника на початок файлу.

    // Приклад: є файл з текстовими даними. Найти всі букви "a" і замінити їх на букви "A".
    {

        FILE* fileStream = nullptr;
        const char* filename = "Good text.txt";

        fopen_s(&fileStream, filename, "r+");
        if (fileStream != nullptr)
        {
            int character;
            while ((character = fgetc(fileStream)) != EOF)
            {
                if (character == 'a')
                {
                    fseek(fileStream, -1, SEEK_CUR);
                    fputc('A', fileStream);
                    fseek(fileStream, 1, SEEK_CUR);
                }
            }
            fclose(fileStream);
        }
    }
}

int main()
{
    // Як указуються шляхи до файлів?
    {
        // Шлях до файлу - це текст наступних видів:
        // 1. "Папка\\Папка\\Папка\\Папка\\Файл.Розширення"
        // Наприклад: R"(D:\Documents\Visual Studio 2022\MyFile.txt)"
        // 2. "Папка/Папка/Папка/Папка/Файл.Розширення"
        // Наприклад: "D:/Documents/Visual Studio 2022/MyFile.txt"
    }

    // Створення папок:
    CreateFolder();

    // Перейменування папок:
    RenameFolder();

    // Видалення папок:
    DeleteFolder();

    // Створення файлів:
    CreateFile();

    // Перейменування файлів:
    RenameFile();

    // Видалення файлів:
    DeleteFile();

    // Закриття файлів
    CloseFile();

    // Читання інформації з файлу:
    ReadFromFile();

    // Запис інформації у файл:
    WriteIntoFile();

    // Переміщення позиції файлових вказівників
    FilePositioning();
}