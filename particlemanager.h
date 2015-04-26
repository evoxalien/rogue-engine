#ifndef PARTICLE_MANAGER_
#define PARTICLE_MANAGER_
#include "SDLincludes.h"
#include "particle.h"
#include "particlestate.h"
#include "Texture.h"
#include "mathutil.h"
#include <cmath>
#include <stdlib.h>


template<typename T>
class ParticleManager 
{
    public:
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
    private:
        function<Particle> updateParticle;
        CircularParticleArray particleList;
        int ParticleCount;
    public:

        ParticleManager(int capacity, Action<Particle> updateParticle)
        {
            this.updateParticle = updateParticle;
            particleList = new CircularParticleArray(capacity);

            //Populate the List with Empty Particle objects, for reuse
            for (int i = 0; i < capacity; i++)
                particleList[i] = new Particle();

        }

        //Additional Functions
        static void Swap(CircularParticleArray list, int index1, index2)
        {
            auto temp = list[index1];
            list[index1] = list[index2];
            list[index2] = temp;
        }

        //Create Particle
        void CreateParticle(Texture texture, x, y, SDL_Color color, float duration, Vector2D scale, T state, float theta = 0)
        {
            Particle particle;
            if(particleList.Count == particleList.Capacity)
            {
                //Over write the oldest
                particle = particleList[0];
                particleList.Start++;
            }
            else
            {
                particle = particleList[particleList.Count];
                particleList.Count++;
            }

            particle.Texture = texture;
            particle.posX = x;
            particle.posY = y;
            particle.Tint = tint;

            particle.Duration = duration;
            particle.PercentLife = 1f;
            particle.Scale = scale;
            particle.Orientation = theta;
            particle.State = state;
        }


        public void Update()
        {
            int removalCount = 0;
            for (int i = 0; i < particleList.Count; i++)
            {
                auto particle = particleList[i];
                updateParticle(particle);
                particle.PercentLife -= 1f / particle.Duration;

                //Now its time to shift the deleted ones to the back of the list
                Swap(particleList, i - removalCount, i);
                ParticleCount = particleList.Count;
                // if the particle has expired, delete this particle
                if (particle.PercentLife < 0)
                    removalCount++;
            }
            particleList.Count -= removalCount;
        }
        
        public void Draw(SpriteBatch spriteBatch)
        {
            for (int i = 0; i < particleList.Count; i++)
            {
                auto particle = particleList[i];

                //Vector2D origin = new Vector2D(particle.Texture.Width / 2, particle.Texture.Height / 2);

                //spriteBatch.Draw(particle.Texture, particle.Position, null, particle.Tint, particle.Orientation, origin, particle.Scale, 0, 0);

            }
        }
};


#endif

/* OLD PARTICLE MANAGER IN C#
public class ParticleManager<T>
    {
        private Action<Particle> updateParticle;
        private CircularParticleArray particleList;
        public int ParticleCount;

        public class Particle
        {
            public Texture2D Texture;
            public Vector2 Position;
            public float Orientation;

            public Vector2 Scale = Vector2.One;

            public Color Tint;
            public float Duration;
            public float PercentLife = 1f;
            public T State;
        }

        public ParticleManager(int capacity, Action<Particle> updateParticle)
        {
            this.updateParticle = updateParticle;
            particleList = new CircularParticleArray(capacity);

            // Populate the list with empty particle objects, for reuse
            for (int i = 0; i < capacity; i++)
                particleList[i] = new Particle();
        }

        #region AddtionalFunctions
        private static void Swap(CircularParticleArray list, int index1, int index2)
        {
            var temp = list[index1];
            list[index1] = list[index2];
            list[index2] = temp;
        }
        #endregion
*/ 
        /*
        #region CreateParticle
        public void CreateParticle(Texture2D texture, Vector2 position, Color tint, float duration, Vector2 scale, T state, float theta = 0)
        {
            Particle particle;
            if (particleList.Count == particleList.Capacity)
            {
                //Over write the oldest
                particle = particleList[0];
                particleList.Start++;
            }
            else
            {
                particle = particleList[particleList.Count];
                particleList.Count++;            
            }

            particle.Texture = texture;
            particle.Position = position;
            particle.Tint = tint;

            particle.Duration = duration;
            particle.PercentLife = 1f;
            particle.Scale = scale;
            particle.Orientation = theta;
            particle.State = state;
        }
        #endregion

        #region ParticleArray
        private class CircularParticleArray
        {
            private int start;
            public int Start
            {
                get { return start; }
                set { start = value % list.Length; }
            }
            public int Count { get; set; }
            public int Capacity { get { return list.Length; } }
            private Particle[] list;

            public CircularParticleArray(int capacity)
            {
                list = new Particle[capacity];
            }

            public Particle this[int i]
            {
                get { return list[(start + i) % list.Length]; }
                set { list[(start + i) % list.Length] = value; }
            }
        }
        #endregion

        #region Update
        public void Update()
        {
            int removalCount = 0;
            for (int i = 0; i < particleList.Count; i++)
            {
                var particle = particleList[i];
                updateParticle(particle);
                particle.PercentLife -= 1f / particle.Duration;

                //Now its time to shift the deleted ones to the back of the list
                Swap(particleList, i - removalCount, i);
                ParticleCount = particleList.Count;
                // if the particle has expired, delete this particle
                if (particle.PercentLife < 0)
                    removalCount++;
            }
            particleList.Count -= removalCount;
        }
        #endregion

        #region Draw
        public void Draw(SpriteBatch spriteBatch)
        {
            for (int i = 0; i < particleList.Count; i++)
            {
                var particle = particleList[i];

                Vector2 origin = new Vector2(particle.Texture.Width / 2, particle.Texture.Height / 2);
                spriteBatch.Draw(particle.Texture, particle.Position, null, particle.Tint, particle.Orientation, origin, particle.Scale, 0, 0);

            }
        }
        #endregion

    }
    */