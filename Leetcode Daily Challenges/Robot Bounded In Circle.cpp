class Solution {
public:
    enum Direction { north, east, south, west };
    void play(int &face, int &x, int &y, string &instr) {
        for(char c : instr) {
            switch(face) {
                case north : {
                    if(c == 'G') {
                        y++;
                    } else if(c == 'L') {
                        face = west;
                    } else {
                        face = east;
                    }
                } break;
                case east : {
                    if(c == 'G') {
                        x++;
                    } else if(c == 'L') {
                        face = north;
                    } else {
                        face = south;
                    }
                } break;
                case south : {
                    if(c == 'G') {
                        y--;
                    } else if(c == 'L') {
                        face = east;
                    } else {
                        face = west;
                    }
                } break;
                case west : {
                    if(c == 'G') {
                        x--;
                    } else if(c == 'L') {
                        face = south;
                    } else {
                        face = north;
                    }
                }
            }
        }
    }
    bool isRobotBounded(string instr) {
        
        int face = north;
        int x = 0, y = 0;
        
        // run1
        play(face, x, y, instr);
    
        
        
        return x == 0 && y == 0 || face != north;
    }
};
