class Robot {
public:
    int w, h;
    int x, y, dir; // 0=E, 1=N, 2=W, 3=S
    int cycle;
    
    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 0; // East
        cycle = 2 * (w + h - 2);
    }
    
    void step(int num) {
        num %= cycle;
        
        // special case
        if(num == 0 && x == 0 && y == 0) {
            dir = 3; // South
            return;
        }
        
        while(num > 0) {
            int move = 0;
            
            if(dir == 0) { // East
                move = min(num, w - 1 - x);
                x += move;
            }
            else if(dir == 1) { // North
                move = min(num, h - 1 - y);
                y += move;
            }
            else if(dir == 2) { // West
                move = min(num, x);
                x -= move;
            }
            else { // South
                move = min(num, y);
                y -= move;
            }
            
            num -= move;
            
            if(num > 0) {
                dir = (dir + 1) % 4; // turn CCW
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        if(dir == 0) return "East";
        if(dir == 1) return "North";
        if(dir == 2) return "West";
        return "South";
    }
};