class Heap {
public:
    Heap() = default;

    void insert(int val) {
        v.push_back(val);
        int i = v.size() - 1;
        
        while(i > 0 && v[(i - 1)/2] < v[i]) {
            swap(v[(i-1)/2], v[i]);
            i = (i-1)/2;
        }
    }
    
    bool empty() {
        return v.size() == 0;
    }
    
    int extractMax() {
        int root = v[0];
        
        v[0] = v.back();
        v.pop_back();
        
        if(v.size() > 0)
            heapify(0);
        
        return root;
    }
    
    int getMax() {
        return v[1];
    }
    
private:
    vector<int> v; // indices start from 1
    
    void heapify(int i) {
        int largest = i;
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int size = v.size();
        
        if(left < size && v[left] > v[largest])
            largest = left;
            
        if(right < size && v[right] > v[largest])
            largest = right;
            
        if(largest != i) {
            swap(v[i], v[largest]);
            heapify(largest);
        }
    }
}
