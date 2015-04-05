/*
* Copyright (c) 2006-2009 Erin Catto http://www.box2d.org
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/

#ifndef BOX2D_H
#define BOX2D_H

/**
\mainpage Box2D API Documentation

\section intro_sec Getting Started

For documentation please see http://box2d.org/documentation.html

For discussion please visit http://box2d.org/forum
*/

// These include files constitute the main Box2D API

#include <Box2D/Rope/b2Rope.cpp>

#include <Box2D/Common/b2StackAllocator.cpp>
#include <Box2D/Common/b2BlockAllocator.cpp>
#include <Box2D/Common/b2Settings.h>
#include <Box2D/Common/b2Settings.cpp>
#include <Box2D/Common/b2Draw.h>
#include <Box2D/Common/b2Draw.cpp>
#include <Box2D/Common/b2Math.h>
#include <Box2D/Common/b2Math.cpp>
#include <Box2D/Common/b2Timer.h>
#include <Box2D/Common/b2Timer.cpp>

#include <Box2D/Collision/Shapes/b2ChainShape.cpp>
#include <Box2D/Collision/Shapes/b2EdgeShape.cpp>
#include <Box2D/Collision/Shapes/b2PolygonShape.cpp>
#include <Box2D/Collision/Shapes/b2CircleShape.h>
#include <Box2D/Collision/Shapes/b2CircleShape.cpp>
#include <Box2D/Collision/Shapes/b2EdgeShape.h>
#include <Box2D/Collision/Shapes/b2ChainShape.h>
#include <Box2D/Collision/Shapes/b2PolygonShape.h>

#include <Box2D/Collision/b2BroadPhase.cpp>
#include <Box2D/Collision/b2CollideCircle.cpp>
#include <Box2D/Collision/b2CollideEdge.cpp>
#include <Box2D/Collision/b2CollidePolygon.cpp>
#include <Box2D/Collision/b2Collision.cpp>
#include <Box2D/Collision/b2Distance.cpp>
#include <Box2D/Collision/b2DynamicTree.cpp>
#include <Box2D/Collision/b2TimeOfImpact.cpp>
#include <Box2D/Collision/b2BroadPhase.h>
#include <Box2D/Collision/b2Distance.h>
#include <Box2D/Collision/b2DynamicTree.h>
#include <Box2D/Collision/b2TimeOfImpact.h>

#include <Box2D/Dynamics/b2Body.cpp>
#include <Box2D/Dynamics/b2ContactManager.cpp>
#include <Box2D/Dynamics/b2Fixture.cpp>
#include <Box2D/Dynamics/b2Island.cpp>
#include <Box2D/Dynamics/b2World.cpp>
#include <Box2D/Dynamics/b2WorldCallbacks.cpp>
#include <Box2D/Dynamics/b2Body.h>
#include <Box2D/Dynamics/b2Fixture.h>
#include <Box2D/Dynamics/b2WorldCallbacks.h>
#include <Box2D/Dynamics/b2TimeStep.h>
#include <Box2D/Dynamics/b2World.h>

#include <Box2D/Dynamics/Contacts/b2ChainAndCircleContact.cpp>
#include <Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.cpp>
#include <Box2D/Dynamics/Contacts/b2CircleContact.cpp>
#include <Box2D/Dynamics/Contacts/b2Contact.cpp>
#include <Box2D/Dynamics/Contacts/b2ContactSolver.cpp>
#include <Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.cpp>
#include <Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.cpp>
#include <Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp>
#include <Box2D/Dynamics/Contacts/b2PolygonContact.cpp>
#include <Box2D/Dynamics/Contacts/b2Contact.h>

#include <Box2D/Dynamics/Joints/b2DistanceJoint.cpp>
#include <Box2D/Dynamics/Joints/b2FrictionJoint.cpp>
#include <Box2D/Dynamics/Joints/b2GearJoint.cpp>
#include <Box2D/Dynamics/Joints/b2Joint.cpp>
#include <Box2D/Dynamics/Joints/b2MotorJoint.cpp>
#include <Box2D/Dynamics/Joints/b2MouseJoint.cpp>
#include <Box2D/Dynamics/Joints/b2PrismaticJoint.cpp>
#include <Box2D/Dynamics/Joints/b2PulleyJoint.cpp>
#include <Box2D/Dynamics/Joints/b2RevoluteJoint.cpp>
#include <Box2D/Dynamics/Joints/b2RopeJoint.cpp>
#include <Box2D/Dynamics/Joints/b2WeldJoint.cpp>
#include <Box2D/Dynamics/Joints/b2WheelJoint.cpp>
#include <Box2D/Dynamics/Joints/b2DistanceJoint.h>
#include <Box2D/Dynamics/Joints/b2FrictionJoint.h>
#include <Box2D/Dynamics/Joints/b2GearJoint.h>
#include <Box2D/Dynamics/Joints/b2MotorJoint.h>
#include <Box2D/Dynamics/Joints/b2MouseJoint.h>
#include <Box2D/Dynamics/Joints/b2PrismaticJoint.h>
#include <Box2D/Dynamics/Joints/b2PulleyJoint.h>
#include <Box2D/Dynamics/Joints/b2RevoluteJoint.h>
#include <Box2D/Dynamics/Joints/b2RopeJoint.h>
#include <Box2D/Dynamics/Joints/b2WeldJoint.h>
#include <Box2D/Dynamics/Joints/b2WheelJoint.h>

#endif
