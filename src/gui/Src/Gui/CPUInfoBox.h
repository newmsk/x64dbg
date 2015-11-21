#ifndef INFOBOX_H
#define INFOBOX_H

#include "StdTable.h"
#include <QAction>

class CPUInfoBox : public StdTable
{
    Q_OBJECT
public:
    explicit CPUInfoBox(StdTable* parent = 0);
    int getHeight();
    void addFollowMenuItem(QMenu* menu, QString name, dsint value);
    void setupFollowMenu(QMenu* menu, dsint wVA);

public slots:
    void disasmSelectionChanged(dsint parVA);
    void dbgStateChanged(DBGSTATE state);
    void contextMenuSlot(QPoint pos);
    void followActionSlot();
    void copyAddress();
    void copyRva();
    void copyOffset();

private:
    dsint curAddr;
    dsint curRva;
    dsint curOffset;
    QString getSymbolicName(dsint addr);
    void setInfoLine(int line, QString text);
    QString getInfoLine(int line);
    void clear();
    void setupContextMenu();

    QAction* mCopyAddressAction;
    QAction* mCopyRvaAction;
    QAction* mCopyOffsetAction;
};

#endif // INFOBOX_H
