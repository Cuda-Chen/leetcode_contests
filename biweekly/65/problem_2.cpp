// TLE
class Robot {
public:
    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
    }
    
    void move(int num) {
        while(num) {
            if(dir == 0) {
                if(x + 1 >= w) {
                    dir = (dir + 1) % kMod;
                } else {
                    x += 1;
                    num -= 1;
                }
            } else if(dir == 1) {
                if(y + 1 >= h) {
                    dir = (dir + 1) % kMod;
                } else {
                    y += 1;
                    num -= 1;
                }
            } else if(dir == 2) {
                if(x - 1 < 0) {
                    dir = (dir + 1) % kMod;
                } else {
                    x -= 1;
                    num -= 1;
                }
            } else if(dir == 3) {
                if(y - 1 < 0) {
                    dir = (dir + 1) % kMod;
                } else {
                    y -= 1;
                    num -= 1;
                }
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
    
private:
    int dir = 0; // 0: East, 1: North, 2: West, 3: South 
    int kMod = 4;
    int w, h;
    int x, y; // robot current direction
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
