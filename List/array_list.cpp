#include<iostream>
using namespace std;
#define MAX 5

class list{
    int arr[MAX];
    int size;
    public:
        list(){
            size=0;
        }
        
        void insertAtBeginning(){
            if(size==MAX){
                cout<<"List is full"<<endl;
                return;
            }
            int x;
            cout<<"Enter the value to be inserted: ";
            cin>>x;
            for(int i=size; i>0; i--){
                arr[i]=arr[i-1];
            }
            arr[0]=x;
            size++;
            cout<<"Inserted "<<x<<endl;
        }
        
        void insertAtEnd(){
            if(size==MAX){
                cout<<"List is full"<<endl;
                return;
            }
            int x;
            cout<<"Enter the value to be inserted: ";
            cin>>x;
            arr[size]=x;
            size++;
            cout<<"Inserted "<<x<<endl;
        }
        
        void insertAtPosition(){
            if(size==MAX){
                cout<<"List is full"<<endl;
                return;
            }
            int x,pos;
            cout<<"Enter the value to be inserted: ";
            cin>>x;
            cout<<"Enter position (0 to "<<size<<"): ";
            cin>>pos;
            if(pos<0 || pos>size){
                cout<<"Invalid position"<<endl;
                return;
            }
            for(int i=size; i>pos; i--){
                arr[i]=arr[i-1];
            }
            arr[pos]=x;
            size++;
            cout<<"Inserted "<<x<<" at position "<<pos<<endl;
        }
        
        void deleteFromBeginning(){
            if(size==0){
                cout<<"List is empty"<<endl;
                return;
            }
            cout<<"Deleted "<<arr[0]<<endl;
            for(int i=0; i<size-1; i++){
                arr[i]=arr[i+1];
            }
            size--;
        }
        
        void deleteFromEnd(){
            if(size==0){
                cout<<"List is empty"<<endl;
                return;
            }
            cout<<"Deleted "<<arr[size-1]<<endl;
            size--;
        }
        
        void deleteAtPosition(){
            if(size==0){
                cout<<"List is empty"<<endl;
                return;
            }
            int pos;
            cout<<"Enter position to delete (0 to "<<size-1<<"): ";
            cin>>pos;
            if(pos<0 || pos>=size){
                cout<<"Invalid position"<<endl;
                return;
            }
            cout<<"Deleted "<<arr[pos]<<endl;
            for(int i=pos; i<size-1; i++){
                arr[i]=arr[i+1];
            }
            size--;
        }
        
        void search(){
            if(size==0){
                cout<<"List is empty"<<endl;
                return;
            }
            int x;
            cout<<"Enter value to search: ";
            cin>>x;
            for(int i=0; i<size; i++){
                if(arr[i]==x){
                    cout<<"Found "<<x<<" at position "<<i<<endl;
                    return;
                }
            }
            cout<<"Element not found"<<endl;
        }
        
        void display(){
            if(size==0){
                cout<<"List is empty"<<endl;
                return;
            }
            cout<<"List elements are: ";
            for(int i=0; i<size; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    list l; 
    l.insertAtBeginning();
    l.display();
    l.search();
    l.insertAtEnd();
    l.deleteFromBeginning();
    l.display();
    l.deleteFromEnd();
    l.display();
    
    return 0;
}