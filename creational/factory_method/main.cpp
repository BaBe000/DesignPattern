#include <iostream>
#include <vector>

using namespace std;

class Document {
public:
    Document(string name) : name(name) {};
    virtual void open() = 0;
    virtual void close() = 0;
    string getName(){
        return name;
    }
    virtual string getTypeDocs() = 0;
private:
    string name;
};

class PDF : public Document {
public:
    PDF(string name) : Document(name) {};
    void open() override {
        cout << "Open my pdf of " << Document::getName() << endl;
    }
    void close() override {
        cout << "Close my pdf of " << Document::getName() << endl;
    }
    string getTypeDocs() override {
        return "PDF";
    }
};

class Excel : public Document {
public:
    Excel(string name) : Document(name) {};
    void open() override {
        cout << "Open my excel of " << Document::getName() << endl;
    }
    void close() override {
        cout << "Close my excel of " << Document::getName() << endl;
    }
    string getTypeDocs() override {
        return "Excel";
    }
};

class Application {
public:
    Application() {};
    void addDocument(Document *newDoc) {
        docs.push_back(newDoc);
    }
    void openExcelDocument(string name) {
        for (auto i : docs) {
            if (i->getName() == name  && i->getTypeDocs() == "Excel") {
                i->open();
            }
        }
    }
    void closeExcelDocument(string name) {
        for (auto i : docs) {
            if (i->getName() == name && i->getTypeDocs() == "Excel"){
                i->close();
            }
        }
    }
        void openPDFDocument(string name) {
        for (auto i : docs) {
            if (i->getName() == name  && i->getTypeDocs() == "PDF") {
                i->open();
            }
        }
    }
    void closePDFDocument(string name) {
        for (auto i : docs) {
            if (i->getName() == name && i->getTypeDocs() == "PDF"){
                i->close();
            }
        }
    }
private:
    std::vector<Document*> docs;

};

int main() {
    Application myapp;
    Document *excel1 = new Excel("thai1");
    Document *pdf1 = new PDF("thai1");
    Document *excel2 = new Excel("thai2");
    Document *pdf2 = new PDF("thai2");
    myapp.addDocument(excel1);
    myapp.addDocument(pdf1);
    myapp.addDocument(excel2);
    myapp.addDocument(pdf2);

    myapp.openExcelDocument("thai2");
    return 0;
}