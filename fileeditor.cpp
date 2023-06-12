#pragma once
#include <iostream>
#include <fstream>
#include "IFileEditor.cpp"
#include <list>
#include <QLabel>
#include <QString>
using namespace std;
class FileEditor : public IFileEditor
{
public:
bool existing = 1;
int size = 0;
fstream file;
bool edited = 0;
FileEditor()
{
    existing = 0;
}
FileEditor(const string& path)
{

    file.open(path);
     if (file.fail())
     existing = 0;
     else
     {
         file.seekg(0, ios::end);
         size = file.tellg();

     }
     file.seekg(0, ios::beg);
}

FileEditor (const FileEditor& other)
{
    this->existing=other.existing;
  //  other.path
    this->size=other.size;
    this->edited=other.edited;
    this->message_=other.message_;
    this->list_observer_=other.list_observer_;
}



 void OpenFile(const char* path) {
     if (existing)
     file.close();
     file.open(path);
     if (file.fail())
     {
         existing = 0;
     }
     else
     {
         file.seekg(0, ios::end);
         size = file.tellg();
         existing = 1;
     }
     Notify();
 }
 ~FileEditor() {
     if (existing)
     file.close();
 }

void Write(string data) {
     if (existing)
     {
      file.seekg(0, ios::end);
         file << data;
         edited = 1;

         size = file.tellg();
        // cout << size;
     }
     Notify();

 }
 void Attach(IObserver* observer) override {
     list_observer_.push_back(observer);

 }
 void Detach(IObserver* observer) override {
     list_observer_.remove(observer);
 }
 void Notify() override { //!!!!!!!!!!!!!!!!
     list<IObserver*>::iterator iterator = list_observer_.begin();

     while (iterator != list_observer_.end()) {
         (*iterator)->Update(size, existing);

         ++iterator;
     }
 }

 void SomeBusinessLogic() {
     this->message_ = "change message message";
     Notify();
     cout << "I'm about to do some thing important\n";
 }




 void HowManyObserver() {
     cout << "There are " << list_observer_.size() << " observers in the list.\n";
 }

private:
 list<IObserver*> list_observer_;
 string message_;
};



class observer: public IObserver {
private:
int FileSize = 0;

public:
void Update (int size, bool existing=0)override {
    FileSize = size;
    EmptyCheck();
}
void EmptyCheck()
{
    if (FileSize >0)
        cout << "файл не пустой\n";
}
};


class EditChecker : public IObserver {
private:
int FileSize = 0;
bool FileExisting = 0;
public:
QString FEd;
void Update(int size, bool existing )override {
    int oldsize = FileSize;
    FileSize = size;
    FileExisting = existing;
    EditCheck(oldsize);
}
void EditCheck(int oldsize)
{
    if ((FileExisting)&&(FileSize>oldsize))
    {

        cout << "файл изменен\t"<< "Размер: " << FileSize<< endl;
            FEd = "файл изменен." ;
    }
}
};


class ExsistingChecker : public IObserver {
private:
bool FileExisting = 0;
int FileSize = 0;


public:
 QString FEx;


void Update(int size, bool existing)override {
    FileExisting = existing;
    FileSize = size;
    ExistingCheck();

}
void ExistingCheck()
{
    if (FileExisting)
    {
        cout << "файл существует!\n";

            FEx = "файл существует. Его размер: " + QString::number(FileSize)  ;

    }
    if (!FileExisting) {  cout << "файл не существует\n";   FEx = "файл не существует"; }


}


};
