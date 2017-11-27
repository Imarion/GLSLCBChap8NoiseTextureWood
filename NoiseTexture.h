#include <QWindow>
#include <QTimer>
#include <QString>
#include <QKeyEvent>

#include <QVector3D>
#include <QMatrix4x4>

#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOpenGLFunctions_4_3_Core>

#include <QOpenGLShaderProgram>

#include "vbocube.h"

#define ToRadian(x) ((x) * M_PI / 180.0f)
#define ToDegree(x) ((x) * 180.0f / M_PI)
#define TwoPI (float)(2 * M_PI)

//class MyWindow : public QWindow, protected QOpenGLFunctions_3_3_Core
class MyWindow : public QWindow, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit MyWindow();
    ~MyWindow();
    virtual void keyPressEvent( QKeyEvent *keyEvent );

private slots:
    void render();

private:
    void initialize();
    void modCurTime();

    void initShaders();
    void CreateVertexBuffer();
    void initMatrices();

    void ReadTexture(GLenum TextureUnit, GLenum TextureTarget, const QString& FileName, bool flip);
    void GenerateTexture(float baseFreq, float persistence, int w, int h, bool periodic);

protected:
    void resizeEvent(QResizeEvent *);

private:
    QOpenGLContext *mContext;
    QOpenGLFunctions_4_3_Core *mFuncs;

    QOpenGLShaderProgram *mProgram;

    QTimer mRepaintTimer;
    double currentTimeMs;
    double currentTimeS;
    bool   mUpdateSize;
    float  tPrev, angle;

    GLuint mVAOCube, mVBO, mIBO;

    VBOCube    *mCube;
    QMatrix4x4 ModelMatrixCube, ViewMatrix, ProjectionMatrix;
    QMatrix4x4 mSlice;

    //debug
    void printMatrix(const QMatrix4x4& mat);
};
