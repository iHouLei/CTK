/*=========================================================================

  Library:   CTK

  Copyright (c) Kitware Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.commontk.org/LICENSE

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=========================================================================*/

#ifndef __ctkQImageViewerWidget_h
#define __ctkQImageViewerWidget_h

/// Qt includes
#include <QWidget>
#include <QImage>

/// CTK includes
#include "ctkPimpl.h"
#include "ctkWidgetsExport.h"

class ctkQImageViewerWidgetPrivate;

///
/// ctkQImageViewerWidget is the base class of image viewer widgets.
class CTK_WIDGETS_EXPORT ctkQImageViewerWidget: public QWidget
{

  Q_OBJECT

public:

  /// Superclass typedef
  typedef QWidget Superclass;

  /// Constructor
  ctkQImageViewerWidget( QWidget* parent = 0 );
  
  /// Destructor
  virtual ~ctkQImageViewerWidget( void );

  double xSpacing( void );
  double ySpacing( void );
  double sliceThickness( void );

  double xPosition( void );
  double yPosition( void );
  double slicePosition( void );
  double positionValue( void );

  double xCenter( void );
  double yCenter( void );

  int sliceNumber( void ) const;
  int numberOfSlices( void ) const;

  double intensityWindowMin( void ) const;
  double intensityWindowMax( void ) const;

  bool flipXAxis( void ) const;
  bool flipYAxis( void ) const;
  bool transposeXY( void ) const;

  double zoom( void );

public slots:

  void addImage( const QImage * image );
  void clearImages( void );

  void setSliceNumber( int slicenum );

  void setIntensityWindow( double iwMin, double iwMax );

  void setFlipXAxis( bool flip );
  void setFlipYAxis( bool flip );
  void setTransposeXY( bool transpose );

  virtual void keyPressEvent( QKeyEvent * event );
  virtual void mousePressEvent( QMouseEvent * event );
  virtual void mouseReleaseEvent( QMouseEvent * event );
  virtual void mouseMoveEvent( QMouseEvent * event );

  void setCenter( double x, double y );
  void setPosition( double x, double y );

  void setZoom( double factor );

  void reset();

  virtual void update( bool zoomChanged=false, bool sizeChanged=false );

signals:

  void xSpacingChanged( double xSpacing );
  void ySpacingChanged( double ySpacing );
  void sliceThicknessChanged( double sliceThickness );

  void xPositionChanged( double xPosition );
  void yPositionChanged( double yPosition );
  void slicePositionChanged( double slicePosition );
  void positionValueChanged( double positionValue );

  void sliceNumberChanged( int sliceNum );

  void zoomChanged( double factor );
  void xCenterChanged( double x );
  void yCenterChanged( double y );

  void numberOfSlicesChanged( int numberOfSlices );

  void flipXAxisChanged( bool flipXAxis );
  void flipYAxisChanged( bool flipYAxis );
  void transposeXYChanged( bool transposeXY );

  void intensityWindowMinChanged( double intensityWindowMin );
  void intensityWindowMaxChanged( double intensityWindowMax );

protected:

  virtual void resizeEvent( QResizeEvent* event );

  /// protected constructor to derive private implementations
  ctkQImageViewerWidget( ctkQImageViewerWidgetPrivate & pvt,
    QWidget* parent=0 );

private:

  QScopedPointer< ctkQImageViewerWidgetPrivate > d_ptr;

  Q_DECLARE_PRIVATE( ctkQImageViewerWidget );

  Q_DISABLE_COPY( ctkQImageViewerWidget );

};

#endif