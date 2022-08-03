struct Event {
    Event(int st, int e) : start(st), end(e) {};
    int start;
    int end;
};

inline bool operator < (const Event &e1, const Event& e2)
{
  return e1.start < e2.start;
}

class MyCalendar {
    set<Event> bookings;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(bookings.empty()) {
            bookings.insert(Event(start, end));
            return true;
        }
        
        int idx = 0, n = bookings.size(), possible = false;
        
        for(auto it = bookings.begin(); it != bookings.end(); ++it) {
            if(idx == 0 and end <= it->start)  {
                possible = true; 
                continue;
            }
            
            if(idx == n - 1 and start >= it->end) {
                possible = true; 
                continue;
            }
            
            auto it_next = it;
            ++it_next;
            
            if(start >= it->end and end <= it_next->start) possible = true;
            
            idx++;
        }
        
        if(possible)
            bookings.insert(Event(start, end));
        
        return possible;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 10 20 25 30
 1. 15 27
 2. 13 16
 3. 19 24
 4. 21 28
 
 s1 e1 s2 e2 s3 e3 => start >= e1 and end < s2 || 
 */