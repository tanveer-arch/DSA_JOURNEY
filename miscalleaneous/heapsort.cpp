#include<iostream>
using namespace std;
 #include<climits>
class minheap{
    public:
    int *hrr;
    int capacity;
    int heap_size;

    minheap(int cap){
        capacity=cap;
        heap_size=cap;
        hrr=new int[cap];
    }

    void printarray(){
        for(int i=0;i<heap_size;i++){
            cout<<hrr[i]<<" ";
        }
    }

    int left(int i){
        return (2*i+1);
    }
    int right(int i){
        return (2*i+2);
    }

    void minheapify(int i){
        int l=left(i);
        int r=right(i);
        int smallest =i;
        if(l<heap_size && hrr[l]<hrr[i]){
            smallest=l;
        }
        if(r<heap_size && hrr[r]<hrr[smallest]){
            smallest=r;
        }
        if(smallest!=i){
            swap(hrr[i],hrr[smallest]);
            minheapify(smallest);
        }
    }

    int extractmin(){
        if(heap_size==0){
            return INT_MAX;
        }
        if(heap_size==1){
            heap_size--;
            return hrr[0];
        }

        int root=hrr[0];
        hrr[0]=hrr[heap_size-1];
        heap_size--;
        minheapify(0);
        return root;
    }

    void getunsortedarray(){
        cout<<"enter elements"<<endl;
        for(int i=0;i<capacity;i++){
            cin>>hrr[i];
        }
    }

    void heapsort()
    {
        int temp[capacity];
        for(int i=0;i<capacity;i++){
            temp[i]=extractmin();
            cout<<temp[i]<<" ";
        }
    }
};

    int main(){
        int s;
        cout<<"enter size of minheap"<<endl;
        cin>>s;
        minheap obj(s);
        obj.getunsortedarray();
        obj.printarray();

        for(int i=s/2-1;i>=0;i--){
            obj.minheapify(i);
        }

        cout<<"\nsorted array"<<endl;
        obj.heapsort();


    }