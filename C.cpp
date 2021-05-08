#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

class Person{
    public:
        int id;
        int idol_n;
        int fans_n;
        bool in_room;
        Person **idols;

        Person(){
            id = 0;
            idol_n = 0;
            fans_n = 0;
            in_room = false;
            idols = NULL;
        }

        void introduce(){
            if(in_room)
                cout << "I'm " << id << " and I'm in the room." << endl;
            else
                cout << "I'm " << id << " and I'm not in the room." << endl;
            cout << "I have " << fans_n << " fan(s)" << endl;
            cout << "I have " << idol_n << " idol(s)." << endl;
            cout << "They are: ";
            for(int i=0;i<idol_n;i++){
                cout << idols[i]->id << " ";
            }
            cout<<endl<<endl;

        }
};

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int people_N, inroom_N;
    cin >> people_N >> inroom_N;

    Person *persons = new Person[people_N+1];
    for(int i=0;i<=people_N;i++){
        persons[i].id = i;
    }

    // Read data
    for(int id=0 ; id<inroom_N ; id++){
        int guest, guest_idols;
        cin >> guest >> guest_idols;

        persons[guest].in_room = true;
        persons[guest].idols = new Person*[guest_idols];
        persons[guest].idol_n = guest_idols;

        if(guest_idols == 0){
            cin >> guest_idols;
            continue;
        }

        for(int i=0;i<guest_idols;i++){
            int idol_id;
            cin >> idol_id;
            persons[guest].idols[i] = &persons[idol_id];
        }
    }

    // Invalid not in room
    for(int id=1 ; id <= people_N ; id++){
        if(persons[id].in_room == false)
            continue;
        Person *thisguy = &persons[id];
        int idol_N = thisguy->idol_n;
        thisguy->idol_n = 0;
        
        for(int i=0; i<idol_N; i++){
            Person *idol = thisguy->idols[i];
            if(idol->in_room){
                thisguy->idol_n++;
                idol->fans_n++;
            }
        }
    }

    //Evaluate
    bool haveCele = false;
    for(int i=0;i<=people_N;i++){
        Person *thisguy = &persons[i];
        // thisguy->introduce();
        if(!thisguy->in_room)
            continue;
        int fn = thisguy->fans_n;
        int in = thisguy->idol_n;

        if(fn==inroom_N-1 && fn != 0 && in==0){
            cout << thisguy->id << endl;
            haveCele = true;
            break;
        }

    }

    if(!haveCele){
        cout << "-1" << endl;
    }


    return 0;

}