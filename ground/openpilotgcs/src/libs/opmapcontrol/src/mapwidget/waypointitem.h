/**
******************************************************************************
*
* @file       waypointitem.h
* @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2012.
* @brief      A graphicsItem representing a WayPoint
* @see        The GNU Public License (GPL) Version 3
* @defgroup   OPMapWidget
* @{
*
*****************************************************************************/
/*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
*
* You should have received a copy of the GNU General Public License along
* with this program; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
#ifndef WAYPOINTITEM_H
#define WAYPOINTITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include <QLabel>
#include "../internals/pointlatlng.h"
#include "mapgraphicitem.h"
#include <QObject>
#include <QPoint>

namespace mapcontrol
{
struct distBearingAltitude
{
    double distance;
    double bearing;
    float altitudeRelative;
    double bearingToDegrees(){return bearing*180/M_PI;}
    void setBearingFromDegrees(double degrees){bearing=degrees*M_PI/180;}
};
class HomeItem;
/**
* @brief A QGraphicsItem representing a WayPoint
*
* @class WayPointItem waypointitem.h "waypointitem.h"
*/
class WayPointItem:public QObject,public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    enum { Type = UserType + 1 };
    enum wptype {absolute,relative};
    /**
    * @brief Constructer
    *
    * @param coord coordinates in LatLng of the Waypoint
    * @param altitude altitude of the WayPoint
    * @param map pointer to map to use
    * @return
    */
    WayPointItem(internals::PointLatLng const& coord,int const& altitude,MapGraphicItem* map,wptype type=absolute);
    WayPointItem(MapGraphicItem* map,bool magicwaypoint);
    /**
    * @brief Constructer
    *
    * @param coord coordinates in LatLng of the WayPoint
    * @param altitude altitude of the WayPoint
    * @param description description fo the WayPoint
    * @param map pointer to map to use
    * @return
    */
    WayPointItem(internals::PointLatLng const& coord,int const& altitude,QString const& description,MapGraphicItem* map,wptype type=absolute);
    WayPointItem(distBearingAltitude const& relativeCoord,QString const& description,MapGraphicItem* map);

    /**
    * @brief Returns the WayPoint description
    *
    * @return QString
    */
    QString Description(){return description;}
    /**
    * @brief Sets the WayPoint description
    *
    * @param value
    */
    void SetDescription(QString const& value);
    /**
    * @brief Returns true if WayPoint is Reached
    *
    * @return bool
    */
    bool Reached(){return reached;}
    /**
    * @brief  Sets if WayPoint is Reached
    *
    * @param value
    */
    void SetReached(bool const& value);
    /**
    * @brief Returns the WayPoint number
    *
    */
    int Number(){return number;}
    int numberAdjusted(){return number+1;}
    /**
    * @brief Sets WayPoint number
    *
    * @param value
    */
    void SetNumber(int const& value);
    /**
    * @brief Returns WayPoint LatLng coordinate
    *
    */
    internals::PointLatLng Coord(){return coord;}
    /**
    * @brief  Sets WayPoint LatLng coordinate
    *
    * @param value
    */
    void SetCoord(internals::PointLatLng const& value);
    /**
    * @brief Used if WayPoint number is to be drawn on screen
    *
    */
    bool ShowNumber(){return shownumber;}
    /**
    * @brief  Used to set if WayPoint number is to be drawn on screen
    *
    * @param value
    */
    void SetShowNumber(bool const& value);
    /**
    * @brief Returns the WayPoint altitude
    *
    * @return int
    */
    float Altitude(){return altitude;}
    /**
    * @brief Sets the WayPoint Altitude
    *
    * @param value
    */
    void SetAltitude(const float &value);
    void setRelativeCoord(distBearingAltitude value);
    distBearingAltitude getRelativeCoord(){return relativeCoord;}
    int type() const;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                QWidget *widget);
    void RefreshToolTip();
    QPixmap picture;
    QString customString(){return myCustomString;}
    void setCustomString(QString arg){myCustomString=arg;}
    void setFlag(GraphicsItemFlag flag, bool enabled);
~WayPointItem();

    static int snumber;
    void setWPType(wptype type);
    wptype WPType(){return myType;}
protected:
    void mouseMoveEvent ( QGraphicsSceneMouseEvent * event );
    void mousePressEvent ( QGraphicsSceneMouseEvent * event );
    void mouseReleaseEvent ( QGraphicsSceneMouseEvent * event );
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
private:
    internals::PointLatLng coord;//coordinates of this WayPoint
    distBearingAltitude relativeCoord;
    bool reached;
    QString description;
    bool shownumber;
    bool isDragging;
    float altitude;
    MapGraphicItem* map;
    int number;
    bool isMagic;

    QGraphicsSimpleTextItem* text;
    QGraphicsRectItem* textBG;
    QGraphicsSimpleTextItem* numberI;
    QGraphicsRectItem* numberIBG;
    QTransform transf;
    HomeItem * myHome;
    wptype myType;
    QString myCustomString;

public slots:
    /**
    * @brief Called when a WayPoint is deleted
    *
    * @param number number of the WayPoint that was deleted
    */
    void WPDeleted(int const& number,WayPointItem *waypoint);
    /**
    * @brief Called when a WayPoint is renumbered
    *
    * @param oldnumber the old  WayPoint number
    * @param newnumber the new WayPoint number
    * @param waypoint a pointer to the WayPoint renumbered
    */
    void WPRenumbered(int const& oldnumber,int const& newnumber,WayPointItem* waypoint);
    /**
    * @brief Called when a  WayPoint is inserted
    *
    * @param number the number of the  WayPoint
    * @param waypoint  a pointer to the WayPoint inserted
    */
    void WPInserted(int const& number,WayPointItem* waypoint);

    void onHomePositionChanged(internals::PointLatLng,float altitude);
    void RefreshPos();
    void setOpacitySlot(qreal opacity);
signals:
    /**
    * @brief fires when this WayPoint number changes (not fired if due to a auto-renumbering)
    *
    * @param oldnumber this WayPoint old number
    * @param newnumber this WayPoint new number
    * @param waypoint a pointer to this WayPoint
    */
    void WPNumberChanged(int const& oldnumber,int const& newnumber,WayPointItem* waypoint);

    /**
    * @brief Fired when the description, altitude or coordinates change
    *
    * @param waypoint a pointer to this WayPoint
    */

    /**
    * @brief Fired when the waypoint is dropped somewhere
    *
    * @param waypoint a pointer to this WayPoint
    */
    void WPDropped(WayPointItem* waypoint);

    void WPValuesChanged(WayPointItem* waypoint);
    void waypointdoubleclick(WayPointItem* waypoint);
    void localPositionChanged(QPointF point,WayPointItem* waypoint);
    void manualCoordChange(WayPointItem *);
    void aboutToBeDeleted(WayPointItem *);
};
}
#endif // WAYPOINTITEM_H
