// 1. �� ���������� ����� �� �����?
// 2. �� �������� �����?
// 3. �� ������������� �����?
// 4. �� �������� �����?
// 5. �� �������� ����?
// 6. �� ������������� ����?
// 7. �� �������� ����?
// 8. �� ��������� ���������� �����?
// 9. ������� ������ ����� � ������
// 10. ������� � ����� �����
// 11. �� ������� ����?
// 12. ��������� ������� � ����
// 13. �� ���� EOF?
// 14. �� ������� ���������� � �����?
// 15. �� �������� � ���� ����������?
// 16. ���������� ������� �������� ���������


// ����������� ���������
#include <iostream>
#include <string>
#include <direct.h> // ��� _mkdir()

// ������� ��� ����������� ��������� �� ������
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

// ����������� ���������
struct Person
{
    char name[50]{};
    int age;
};

// �������� � �������
void CreateFolder()
{
    const char* folder1Name = "MyFolder";
    const wchar_t* folder2Name = L"��� �����";
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

// �������� � �������
void CreateFile()
{
    // ������� ���������/�������� ����� fopen:
    // ��������:  FILE* fopen (const char* filename, const char* mode)
    // ���������: filename - ���� �� ����� ����� � ������ �� �����������
    //            mode     - ����� �������� �����
    // ���������� ��������: �������� �� �������� ����. nullptr  - ���� �� ������� �������/��������.
    // 
    // ������: ��� ���� wchar_t ���� ������� _wfopen.
    // 
    // FILE - �� ���������, ��� ������ ���� ���� ���� - �������� �� ����.
    // 
    // �����: ��������� VS �� ������������� �� �������� ��������������� ������� fopen,
    //        �� ����� �� �����������. ³� ��������� ��������������� ��������
    //        ������� fopen_s().
    //
    // ������� ���������/�������� ����� fopen_s:
    // ��������:  errno_t fopen(FILE** stream, const char* filename, const char* mode)
    // ���������: stream - ������ �� �������� ���� File, �� ����� ����'������� ����
    //            filename - ���� �� ����� ����� � ������ �� �����������
    //            mode     - ����� �������� �����
    // ���������� ��������: 0 - ���� ������ �������, ��������� EINVAL � ����� ��������..
    // 
    // ������: ��� ���� wchar_t ���� ������� _wfopen_s.
    // 
    // ������ �������� �����:
    // "r"  - ������� ���� ��� �������. ���� ����� �� ���� �� ���� ��������� ����� 
    //       ����������� nullptr.
    // "w"  - ������� ������ ���� ��� ������. ���� ���� ����, �� ���� ���� �����������.
    // "a"  - ������� ���� ��� ������ � ���� �����. ������� ����, ���� ���� �� ����.
    // "r+" - ������� ���� ��� ������� � ��� ������. ���� �� ��������.
    // "w+" - ������� ������ ���� ��� ������� � ��� ������. ���� ���� ����, 
    //        �� ���� ���� �����������.
    // "a+" - ������� ���� ��� ������� � ��� ������ � ���� �����. ������� ����, ���� ���� �� ����.
    //
    // ������� �������� ����� fopen:
    // FILE* file1;
    // file1 = fopen("sdgsdgh.txt", "r");
    // if (file1 == nullptr)
    //      std::cout << "File could not been opened.\n";
    // 
    // ������� �������� ����� fopen_s:
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
    // ³������ ���� � �'������ � �������
    const char* filename = "SomeFole.txt";
    FILE* file;
    fopen_s(&file, filename, "w");
    while (true)
    { }
    // -------------------
    // ���������� � ������
    // -------------------
    // ������� ����, ��'������� ����.
    fclose(file);
}

// ��������� �������� � �������
void ReadFromFile()
{
    // � ������� ������� ��� ������� ���������� � �����:
    // 
    // 1. ��������:             int fgetc(FILE*stream)
    //    ����:                 ���� � ������� ��������� ������ � ������.
    //    ���������:            stream - ���� �� ����.
    //    ���������� ��������:  �������� ������, ���� ������ �������.
    //                          ������ EOF.
    // 
    // 2. ��������:             char* fgets(char* strm int countm FILE* stream)
    //    ����:                 ���� �������� (count - 1) ������� �� ������ � ������
    //                          �� � ����� str. ���������� �����������, ���� ����������� 
    //                          ������ \n ��� ����� �����. ������ ����-������ � �����
    //                          ������� �����������.
    //    ���������:            str     - �����, ���� ���������� �������
    //                          count   - ����� ������ str
    //                          stream  - ���� �� ����.
    //    ���������� ��������:  str, ���� ������ ������� ������� �����������.
    //                          nullptr, ���� ������� ��������.
    // 
    // 3. ��������:             size_t fread(void* buffer, size_t size, size_t count, FILE* stream)
    //    ����:                 ����� �������� count ����� � �������� buffer �� ������ stream
    //    ���������:            buffer  - ��������, ���� ���������� �����
    //                          size    - ����� ������� �������� ����������� �����, �� ����� �������
    //                          count   - ������� ����� ��� ����������. 
    //                          stream  - ���� �� ����
    //    ���������� ��������:  ������� ������ �������� �����.
 
    // ������� ������������ fgetc:
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
    
    // ������� ������������ fgets:
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
    // ������� ������������ fread:
    {
        int intVariable = 10;
        const size_t SIZE = 3;
        char charArray[SIZE] = { 'A', 'B', 'C' };
        Person demian{ "Demian", 25 };

        // �������� �������� ��� � ����:
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

        // ����� ���� ���, ��� ���� �������, �� ���������� � ����� ����� ���������.
        intVariable = 0;
        charArray[0] = '\0';
        demian.age = 0;
        demian.name[0] = '\0';

        // � ����� ������� ���������� � �����:
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

        // ����������, �� ��������� �����.
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
    // � ������� ������� ��� ������ ���������� � ���� :
    // 
    // 1. ��������:          int fputc(int ch, FILE * stream);
    //  ����:                ������ ������ ch � �������� ���� stream
    //  ���������:           ch      - ������
    //                       stream  - ����, ��'������ � ������
    //  ���������� ��������: ���� ������ ������ ��������� - ������� ������.
    //                       ������  - EOF.
    // 
    // 2. ��������:          int fputs(const char* str, FILE * stream);
    //  ����:                ������ ����� str � �������� ���� stream
    //  ���������:           str     - �����
    //                       stream  - ����, ��'������ � ������
    //  ���������� ��������: ���� ����� ������ ��������� - ������� ��������� ��������.
    //                       ������  - EOF.
    // 
    // 3. ��������:         size_t fwrite(const void* buffer, size_t size, size_t count, FILE * stream);
    //  ����:               ������ ���, �� �� ����� buffer, � �������� ���� stream
    //  ���������:          buffer - �������� �� ���, �� ����� ��������
    //                      size - ����� ������� �������� �����, �� ����� ��������
    //                      count - ������� �������� �����, �� ����� ��������
    //                      stream - ����, ��'������ � ������
    // ���������� ��������: ʳ������ ��'����, �� ���������� ������.
    //                      ���� �� �������� ����� �� count - ���� ���� �� ���.

    // ������� ������������ ������� fputc:
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

    // ������� ������������ ������� fputs:
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

    // ������� ������������ ������� fwrite:
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
    // ������� � ���� � ��������� �� ������� ������� ��� ����������, �� �� ������
    // ��������� � ����.���������, ���� �� ������������� ������� ��� ������� �� ������,
    // �� ���� ���������� �������� �� ������� ���������� �� ��������� ���.

    // ������� ��������, ���� ��� ����� ����� ��������������� ��� ��������� ���
    // ���� ��� ����� ���������� �� ����� �� ������.

    // ��� ������ � ����������� � ������� ������� :
    // 1. long ftell(FILE * stream)                         � ������� ������� ��������� ���������.
    // 2. int fseek(FILE * stream, long offset, int origin) � ���������� ������� ��������� ���������.
    // 3. int fgetpos(FILE * stream, fpos_t * pos)          � ������ ������� ��������� ��������� � pos.
    // 4. int fsetpos(FILE * stream, const fpos_t * pos)    � ������� ������� ��������� ��������� � pos.
    // 5. void rewind(FILE * stream)                        � ����� ������� ��������� ��������� �� ������� �����.

    // �������: � ���� � ���������� ������. ����� �� ����� "a" � ������� �� �� ����� "A".
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
    // �� ���������� ����� �� �����?
    {
        // ���� �� ����� - �� ����� ��������� ����:
        // 1. "�����\\�����\\�����\\�����\\����.����������"
        // ���������: R"(D:\Documents\Visual Studio 2022\MyFile.txt)"
        // 2. "�����/�����/�����/�����/����.����������"
        // ���������: "D:/Documents/Visual Studio 2022/MyFile.txt"
    }

    // ��������� �����:
    CreateFolder();

    // �������������� �����:
    RenameFolder();

    // ��������� �����:
    DeleteFolder();

    // ��������� �����:
    CreateFile();

    // �������������� �����:
    RenameFile();

    // ��������� �����:
    DeleteFile();

    // �������� �����
    CloseFile();

    // ������� ���������� � �����:
    ReadFromFile();

    // ����� ���������� � ����:
    WriteIntoFile();

    // ���������� ������� �������� ���������
    FilePositioning();
}