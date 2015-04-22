#ifndef PARTICLE_H_
#define PARTICLE_H_
#include "vector2d.h"
#include <cmath>
#include "mathutil.h"

typedef bitset<8> BYTE;

enum ParticleType { None, IgnoreGravity};

struct ParticleState
{

	public:
		Vector2D Velocity;
		ParticleType Type;
		float LengthMultiplier

		ParticleState(Vector2D velocity, ParticleType type, float lengthMultiplier = 1f)
		{
			Velocity = velocity;
			Type = type;
			LengthMultiplier = lengthMultiplier;
		} 

		static ParticleState GetRandom(float minVel, float maxVel)
		{
			auto state = new ParticleState();
			state.Velocity = rand.NextVector2(minVel, maxVel);
		}

        static void UpdateParticle(ParticleManager<ParticleState>.Particle particle)
        {
            auto vel = particle.State.Velocity;
            float speed = vel.Length();
            float alpha = min(1, min(particle.PercentLife * 2, speed * 1f));
            alpha *= alpha;
            particle.Position += vel;
            particle.Orientation = vel.ToAngle();
/*
            if (particle.State.Type != ParticleType.IgnoreGravity)
            {
                foreach (auto blackHole in EntityManager.BlackHoles)
                {
                    auto dPos = blackHole.Position - particle.Position;
                    float distance = dPos.Length();
                    auto n = dPos / distance;
                    vel += 10000 * n / (distance * distance + 10000);

                    // add tagentia acceleration for neary particles
                    if (distance < 400)
                        vel += 45 * new Vector2(n.Y, -n.X) / (distance + 100);

                }
            }
            */

            particle.Tint.A = (BYTE)(255 * alpha);

            //particle.Scale.X = particle.State.LengthMultiplier * Math.Min(Math.Min(1f, 0.2f * speed + 0.1f), alpha);
            particle.Scale.X = particle.State.LengthMultiplier * min(min(1f, 0.2f * speed + 0.1f), alpha);
            //denormalized floats cause significant performance issues
            if (abs(vel.X) + abs(vel.Y) < 0.00000000001f)
                vel = Vector2.Zero;

            vel *= 0.97f;
            particle.State.Velocity = vel;
        }
};

};

/* Portion of the OLD C# Code
public struct ParticleState
    {
        static Random rand = new Random();
        public Vector2 Velocity;
        public ParticleType Type;
        public float LengthMultiplier;

        public ParticleState(Vector2 velocity, ParticleType type, float lengthMultiplier = 1f)
        {
            Velocity = velocity;
            Type = type;
            LengthMultiplier = lengthMultiplier;
        }

        public static ParticleState GetRandom(float minVel, float maxVel)
        {
            var state = new ParticleState();
            state.Velocity = rand.NextVector2(minVel, maxVel);
            state.Type = ParticleType.None;
            state.LengthMultiplier = 1;

            return state;
        }

        #region UpdateParticle
        public static void UpdateParticle(ParticleManager<ParticleState>.Particle particle)
        {
            var vel = particle.State.Velocity;
            float speed = vel.Length();
            float alpha = Math.Min(1, Math.Min(particle.PercentLife * 2, speed * 1f));
            alpha *= alpha;
            particle.Position += vel;
            particle.Orientation = vel.ToAngle();

            if (particle.State.Type != ParticleType.IgnoreGravity)
            {
                foreach (var blackHole in EntityManager.BlackHoles)
                {
                    var dPos = blackHole.Position - particle.Position;
                    float distance = dPos.Length();
                    var n = dPos / distance;
                    vel += 10000 * n / (distance * distance + 10000);

                    // add tagentia acceleration for neary particles
                    if (distance < 400)
                        vel += 45 * new Vector2(n.Y, -n.X) / (distance + 100);

                }
            }

            particle.Tint.A = (byte)(255 * alpha);

            particle.Scale.X = particle.State.LengthMultiplier * Math.Min(Math.Min(1f, 0.2f * speed + 0.1f), alpha);
            //denormalized floats cause significant performance issues
            if (Math.Abs(vel.X) + Math.Abs(vel.Y) < 0.00000000001f)
                vel = Vector2.Zero;

            vel *= 0.97f;
            particle.State.Velocity = vel;
        }
        #endregion
*/

    }



#endif