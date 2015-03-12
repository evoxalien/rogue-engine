#include "Camera.h"

void Camera::Camera(int xPos, int yPos, int width, int height, string sType)
{
  set_Dimensions(width,height);
  set_Position(xPos,yPos);
  if(sType != NULL)
  {
    if(sType == "MOVING" || sType == "STATIC")
    {
    set_Type(sType);
    }
    else
    {
    set_Type("STATIC");
    }
  }
}//End of Constructor

void Camera::set_Dimensions(int width,int height)
{ 
  CameraWidth = width;
  CameraHeight = height;
}

void Camera::set_Position(int x,int y)
{ 
  xPos = x; 
  yPos = y;
}

void Camera::set_Type(string sCamType)
{ 
  Camera_Type = sCamType; 
}

string Camera::get_Type()
{ 
  return Camera_Type;
}

void Camera::void update_Camera(int x,int y)
{
  if( bCinematic != true){
    if(get_Type() != "STATIC")
    {
      xPos += x;
      yPos += y;
    }
  }
}//End of Update
