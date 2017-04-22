# device-driver-controlling-brightness-through-mouse

Intro:
  This was a part of our OS Project.

Description:
  One can change the brightness of the monitor by the increase or decrease in the slope of the mouse pointer co-ordinates

How is it done:
        
        1. Exploring the changes in mouse pointer movements:  "/dev/input/mice"
        
        2.  Changing the brightness controls accordingly:   "/sys/class/backlight/intel_backlight/brightness"
          
      
