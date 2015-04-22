#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "SDLincludes.h"
#include "Texture.h"
#include "mathutil.h"
#include <cmath>
#include <stdlib.h>

class Color
{
    public:
        int r, g, b, a;
};

/*
class Particle
{
    public:
        //Texture
        int posX, posY;
        float Orientation;

        Vector2D Scale = new Vector2D(1,1);

        Color Tint;
        float Duration;
        float PercentLife = (float)1.0;
        ParticleState State;

};

class CircularParticleArray
{
    private:
        int start;
        Particle[] list;

    public:
       int getStart() { return start; }
       void setStart(int value) { start = value % list.Length; }

        int Count { get; set; }
        int Capacity { get { return list.Length; } }

        CircularParticleArray(int capacity)
        {
            list = new Particle[capacity];
        }


        Particle getParticle(int i) { return list[(start + i) % list.Length]; }
        void setParticle(int i, Particle value) { list[(start + i) % list.Length] = value; }

};
*/
#endif