1041. Robot Bounded In Circle  - Medium

On an infinite plane, a robot initially stands at (0, 0) and faces north. The robot can receive one of three instructions:

"G": go straight 1 unit;
"L": turn 90 degrees to the left;
"R": turn 90 degrees to the right.
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

Example 1:

Input: instructions = "GGLLGG"
Output: true
Explanation: The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.



class Solution {
public:
    bool isRobotBounded(string instructions) {
        
        int x = 0;
        int y = 0;
        int direction = 0;
        for(int i=0;i<instructions.length();i++){
            switch(instructions[i]){
                case 'L':
                    direction = (direction + 1) % 4;
                    break;
                case 'R':
                    direction = (direction - 1) % 4;
                    break;
                case 'G':
                    switch(direction){
                        case 0:
                            x += 1;
                            break;
                        case 1:case -1:
                            y += 1;
                            break;
                        case 2:case -2:
                            x -= 1;
                            break;
                        case 3:case -3:
                            y -= 1;
                            break;
                    }
                    break;
                default:
                    cout<<"error instructions: "<<instructions[i]<<endl;
            }
        }
        cout << x<<" "<<y<<" "<<direction;
        int now_x = x;
        int now_y = y;
        int now_dir = direction;
        for(int i=0; i<4; i++){
            if(now_x==0 && now_y==0)
                return true;
            switch(direction){
                case 0:
                    return false;
                case 1:case -1:
                    return true;
                    break;
                case 2:case -2:
                    return true;
                case 3:case -3:
                    return true;
            }
        }
        return 0;
    }
        
    
};