#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QTranslator>
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QFileSystemModel>
#include <QTextEdit>
#include <QTreeWidget>
#include <QMdiArea>
#include <QFont>
#include "settings.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TextEditor; }
QT_END_NAMESPACE

class TextEditor : public QMainWindow
{
    Q_OBJECT

public:
    TextEditor(QWidget *parent = nullptr);
    ~TextEditor();

    int sequenceNumber = 0;


private slots:
    void newDocument();

    void open();

    void openForRead();

    void save();

    void saveAs();

    void exit();

    void about();

    void switchLanguage(const QString &language);

    void settings();

    void selectFont();

    bool eventFilter(QObject *watched, QEvent *event) override;

    void print();

    void currentWindow();

    void copyFont();

    void pasteFont();

    void leftAlign();

    void centerAlign();

    void rightAlign();

    void justifyAlign();
private:
    Ui::TextEditor *ui;
    QString currentFile, sPath;
    QTranslator translator;
    Settings parameters;
    QFileSystemModel *dirmodel;
    QMdiArea* mdi_area_{};
    QTextEdit * textEdit;
    QFont copiedFont;
public slots:
    void slotLang(const QString &language);
};
#endif // TEXTEDITOR_H
