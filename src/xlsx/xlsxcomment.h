#ifndef xlsxcomment_h__
#define xlsxcomment_h__
class QXmlStreamWriter;
#include "xlsxrichstring.h"
#include <QMetaType>
#include <QString>
QT_BEGIN_NAMESPACE_XLSX
class CommentPrivate;
class RichString;
class CommentFormat;
class Q_XLSX_EXPORT Comment
{
    Q_DECLARE_PRIVATE(Comment)
public:
    Comment();
    Comment(const QString& auth, const RichString& txt);
    Comment(const Comment& other);
    virtual ~Comment();
    const QString& author() const;
    const RichString& text() const;
    void setAuthor(const QString& auth);
    void setText(const RichString& txt);
    Comment& operator=(const Comment &other);
    const CommentFormat& format() const;
    void setFormat(const CommentFormat& val);
private:
    CommentPrivate* d_ptr;
    friend class Worksheet;
    friend class WorksheetPrivate;
    friend Q_XLSX_EXPORT bool operator==(const Comment &rs1, const Comment &rs2);
    friend Q_XLSX_EXPORT bool operator!=(const Comment &rs1, const Comment &rs2);
};
Q_XLSX_EXPORT bool operator==(const Comment &rs1, const Comment &rs2);
Q_XLSX_EXPORT bool operator!=(const Comment &rs1, const Comment &rs2);
#ifndef QT_NO_DEBUG_STREAM
Q_XLSX_EXPORT QDebug operator<<(QDebug dbg, const Comment &rs);
#endif
QT_END_NAMESPACE_XLSX
Q_DECLARE_METATYPE(QXlsx::Comment)
#endif // xlsxcomment_h__