/*
 * ScalarWidget.h - Class for editing one-dimensional component transfer function.
 *
 * Author: Patrick O'Leary
 * Created: January 19, 2008
 * Copyright: 2008. All rights reserved.
 */
#ifndef SCALARWIDGET_INCLUDED
#define SCALARWIDGET_INCLUDED

#include <GL/gl.h>

/* Vrui includes */
#include <GLMotif/Container.h>
#include <GLMotif/Event.h>
#include <GLMotif/Types.h>
#include <GLMotif/Widget.h>
#include <Misc/CallbackList.h>

#include <DATASTRUCTURE/Gaussian.h>

#define RED_COMPONENT 0
#define GREEN_COMPONENT 1
#define BLUE_COMPONENT 2
#define ALPHA_COMPONENT 3

#define UP_RAMP 0
#define DOWN_RAMP 1
#define CONSTANT_RAMP 2
#define SEISMIC_RAMP 3

#define dist2(x1,y1,x2,y2) (((x2)-(x1))*((x2)-(x1)) + ((y2)-(y1))*((y2)-(y1)))
#define dist3(x1,y1,z1,x2,y2,z2) (((x2)-(x1))*((x2)-(x1)) + ((y2)-(y1))*((y2)-(y1)) + ((z2)-(z1))*((z2)-(z1)))


// begin Forward Declarations
class ScalarWidgetControlPoint;
class ScalarWidgetStorage;
class Volume;
// end Forward Declarations

enum Mode {
    modeNone, modeX, modeH, modeW, modeWR, modeWL, modeB
};

class ScalarWidget: public GLMotif::Widget {
public:
    ScalarWidget(const char* _name, GLMotif::Container* _parent, Volume* volume, int _component, bool _manageChild = true);
    virtual ~ScalarWidget(void);
    void addGaussian(float x, float h, float w, float bx, float by);
    void calculateHistogram(void);
    virtual GLMotif::Vector calcNaturalSize(void) const;
    void create(int ramp);
    void create(int ramp, int component);
    void create(int rampCreationType, double _minimum, double _maximum);
    void create(int ramp, double _minimum, double _maximum, int component);
    void deleteControlPoint(void);
    void deleteControlPoints(void);
    ScalarWidgetControlPoint* determineControlPoint(GLMotif::Event& event);
    virtual void draw(GLContextData& contextData) const;
    void drawArea(void) const;
    void drawControlPoints(void) const;
    void drawHistogram(void) const;
    void drawLine(void) const;
    void drawMargin(void) const;
    void exportScalar(unsigned char* _scalar) const;
    void exportScalar(unsigned char* colormap, int component);
    bool findGaussianControlPoint(float x, float y, float z);
    virtual bool findRecipient(GLMotif::Event& event);
    Misc::CallbackList& getChangedCallbacks(void);
    void setComponent(int component);
    Misc::CallbackList& getControlPointChangedCallbacks(void);
    float getControlPointScalar(void);
    void setControlPointScalar(float _scalar);
    void setControlPointSize(GLfloat _controlPointSize);
    void setControlPointValue(double _value);
    bool isDragging(void) const;
    bool getGaussian(void);
    void setGaussian(bool gaussian);
    void setMarginWidth(GLfloat _marginWidth);
    int getNumberOfControlPoints(void) const;
    void getOpacities(void);
    void getOpacities(int component);
    void setPreferredSize(const GLMotif::Vector& _preferredSize);
    void getScalar(float* _scalar);
    ScalarWidgetStorage* getStorage(void) const;
    void setStorage(ScalarWidgetStorage* _scalarStorage);
    const std::pair<double,double>& getValueRange(void) const;
    void insertControlPoint(double _value);
    void load(const char* fileName);
    virtual void pointerButtonDown(GLMotif::Event& event);
    virtual void pointerButtonUp(GLMotif::Event& event);
    virtual void pointerMotion(GLMotif::Event& event);
    void removeGaussian(int which);
    virtual void resize(const GLMotif::Box& _exterior);
    void save(const char* fileName) const;
    void selectControlPoint(int i);
private:
    ScalarWidgetControlPoint* alphaFirst;
    bool alphaGaussian;
    Gaussian alphaGaussians[20];
    float* alphaHistogram;
    ScalarWidgetControlPoint* alphaLast;
    float * alphaOpacities;
    GLMotif::Box areaBox;
    ScalarWidgetControlPoint* blueFirst;
    bool blueGaussian;
    Gaussian blueGaussians[20];
    float* blueHistogram;
    ScalarWidgetControlPoint* blueLast;
    float * blueOpacities;
    Misc::CallbackList changedCallbacks;
    int component;
    ScalarWidgetControlPoint* controlPoint;
    Misc::CallbackList controlPointChangedCallbacks;
    float controlPointScalar;
    GLfloat controlPointSize;
    int currentGaussian;
    Mode currentMode;
    bool dragging;
    GLMotif::Point::Vector dragOffset;
    ScalarWidgetControlPoint* first;
    ScalarWidgetControlPoint* greenFirst;
     bool greenGaussian;
     Gaussian greenGaussians[20];
     float* greenHistogram;
     ScalarWidgetControlPoint* greenLast;
     float * greenOpacities;
    bool gaussian;
    Gaussian * gaussians;
    float* histogram;
    ScalarWidgetControlPoint* last;
    GLfloat marginWidth;
    int numberOfEntries;
    int numberOfGaussians;
    int numberOfAlphaGaussians;
    int numberOfBlueGaussians;
    int numberOfGreenGaussians;
    int numberOfRedGaussians;
    float * opacities;
    GLMotif::Vector preferredSize;
    ScalarWidgetControlPoint* redFirst;
    bool redGaussian;
    Gaussian redGaussians[20];
    float* redHistogram;
    ScalarWidgetControlPoint* redLast;
    float * redOpacities;
    bool unselected;
    std::pair<double,double> valueRange;
    Volume * volume;
    unsigned char clamp(int x, unsigned char a, unsigned char b) const;
    void saveState(void);
    void updateControlPoints(void);
    void updatePointers(int component);
};

#endif /*SCALARWIDGET_INCLUDED*/
