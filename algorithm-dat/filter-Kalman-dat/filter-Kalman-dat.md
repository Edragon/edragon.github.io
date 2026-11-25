


# filter-Kalman-dat

- [[algorithm-dat]] - [[filter-Kalman-dat]]

a recursive state estimation algorithm.

Instead of using just a single raw measurement, it runs a fast, repeating math loop that takes predictions (from a model of how something moves or changes) and noisy measurements (from sensors), weighs how trustworthy each one is, and outputs a cleaner, best-guess estimate at every step.


## explain like 3 

Imagine you are playing catch in the dark with a glowing ball! 🏀✨

* **Your eyes** are a bit blurry, so when you look, you see *kind of* where the ball is—maybe a little off.
* **Your brain** also knows how fast the ball was moving a second ago, so it can *guess* where it should be next—though gusts of wind might push it a little.

A **Kalman filter** is a smart helper that combines **both**:

1. **Guess:** *"Based on how fast it was moving, I think the ball is right here."*
2. **Look:** *"My blurry eyes see it a tiny bit over there."*
3. **Blend:** *"Let's split the difference—leaning more toward whichever one is less blurry/less wiggly right now!"*

It does this **over and over, super fast**, every fraction of a second. That way, even when your eyes are blurry or the wind blows, you still know where the ball really is!

### Where do we use it in real life?

* **GPS & Maps:** Your phone guesses where you're driving based on your speed and turns, then corrects itself when a GPS signal pops in—keeping the blue dot smooth instead of jumping wildly.
* **Drones, Robots & Self-Driving Cars:** Blending wheel/motor guesses with sensors (like gyroscopes, compasses, or cameras) so they stay steady and know where they're pointing.



## apps 

- [[UAV-dat]] - [[drone-dat]] - [[self-driving-dat]]

## ref 