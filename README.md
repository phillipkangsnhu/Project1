# Project1

In this project, I created a clock where the user can increment the displayed time by one second, one minute, or one hour. One thing I thought I did well was dealing with the display of time, making sure all the digits and the frame were lined up well.  


Some improvements to make would be taking leap second/minutes/hours into account and also being able to increment by more than 1. The most challenging part I found was figuring out how to "clear" the screen after the user selects a menu option. I found that there wasn't really a standard to do this in C++, so I went with flooding the output with newlines to give the impression of a "cleared" screen.  


I think the dive I did into C++ user prompts and the stdlib was transferrable to the other projects and assignments I did for this course. I kept this program maintainable by keeping the naming standards consistent, and adaptable by splitting off most of the logical components into their own functions. It would be easy for a future programmer to come into my code and extend it.
