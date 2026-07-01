This project was me learning C++ in Unreal Engine 5.4, it was a school project where we were tasked with making a new class from C++, as well as 2 AI tasks. 

I really wanted to see what I was capable of after only using Blueprint in Unreal so far. The transition was smoother than I expected, and I think I was able to do some cool stuff in about a week. 




Things I'm most proud of in this project
 
  1.) A custom AI task node, that fires X number shots in the general direction of the player
   
    a.) This uses line traces to determine whether or not the player was hit, then sends a bullet to where the line trace hit at
    b.) The most diffucult part was to not fire the X number of shots all at once at the player. This made me store a cached reference to the AI Controller and the Task Node,
        to finish task outside of the AI Task Nodefunction.
          i.) I did this using a delay between each shot, which was only possible outside of the Task Node function.

 
  2.) A High damaging boss "Beam Shot" that predicts player movement and shows an indicator of where the shot is going to hit
    
    a.) This task got the velocity of the player, and used a variable for Prediction Time, to guess where the player would be after a certain time
    b.) When that calculation is finished, it spawns an indicator to show where the shot is being fired, and doesn't fire until Prediciton Time has passed. 
    c.) This ended up being fairly accurate, however I needed to clamp the Z values of the shot so it wouldn't go super high/low on the Z value if the player was jumping or falling. 
