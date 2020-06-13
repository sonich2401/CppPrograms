#pragma once
#include <windows.h>
#include <string>
#include <sstream>
namespace sb {
    std::string open(std::string Title, std::string fileTypeFullName, std::string fileEx)
    {
        std::wstringstream cls;
        cls << fileTypeFullName.c_str() << "(." << fileEx.c_str() << ")\0*." << fileEx.c_str();
        std::wstring src;
        std::wstring filetypes = cls.str();
        const std::wstring title = L"Select a File";
        std::wstring filename(MAX_PATH, L'\0');
        OPENFILENAMEW ofn = { };
        ofn.lStructSize = sizeof(ofn);
        ofn.hwndOwner = NULL;
        ofn.lpstrFilter = L"Music (.mp3)\0*.mp3\0All\0*.*\0";
        ofn.lpstrFile = &filename[0];
        ofn.nMaxFile = MAX_PATH;
        ofn.lpstrTitle = title.c_str();
        ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;

        if (GetOpenFileNameW(&ofn))
        {
            src = filename;
            std::string str(src.begin(), src.end());
            return str;
        }
        return "NULL";
    }
    std::string save(std::string Title, std::string fileTypeFullName, std::string fileEx)
    {
    return sb::open(Title, fileTypeFullName, fileEx);
    }
}