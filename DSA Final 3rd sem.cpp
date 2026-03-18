#include <iostream>
using namespace std;

struct patient{
	string name;
	string disease;
	int age;
	int id;
	patient *p,*n;
};

struct doctor{
	string name;
	string specialization;
	int id;
	doctor *p,*n;
};

struct appointment{
    int doc_id;
    int pat_id;
    string date;
};


class patientList{
	patient *start,*cur,*temp;
	
	public:
		
		patientList(){
			start = NULL;
			temp = NULL;
		}
		
		~patientList(){
        cur = start;
        while(cur != NULL){
            temp = cur;
            cur = cur->n;
            delete temp;
        }
    }
		
		bool isduplicate(int id){
		cur = start;
	        	while(cur != NULL){
			        if(cur->id == id){
			    	return true;
		    	} cur = cur->n;
		   }	
			return false;
		}
		
		
		bool exists(int id){
        cur = start;
        while(cur != NULL){
            if(cur->id == id)
                return true;
            cur = cur->n;
        }
        return false;
    }
		
		void insert(int i,int a,string d,string n){
			
			if(isduplicate(i)){
				cout<<"\nID must be unique!!\n";
				return;
			}
			
			if(start == NULL){
				start = new patient;
				start->name = n;
				start->disease = d;
				start->age = a;
				start->id = i;
				start->n = NULL;
				start->p = NULL;
			}
			
			else{
				cur = start;
				
				while(cur->n != NULL)
				     cur = cur->n;
				     
				temp = new patient;
				temp->name = n;
				temp->disease = d;
				temp->age = a;
				temp->id = i;
				temp->n = NULL;
				temp->p = cur;
				cur->n = temp;
			}
		}
		void search(int uid){
			cur = start;
			
			if (start == NULL){
				cout<<"List is empty!!\n";
				return;
			}
			
			while(cur != NULL){
				if(cur->id == uid){
					cout<<"\nPatient Found!!\n\n";
					cout<<"ID: "<<cur->id<<"\tName: "<<cur->name<<"\tAge: "<<cur->age<<"\t\tDisease: "<<cur->disease<<endl;
					return;
				}
				cur = cur->n;
			}
			
			cout<<"\nPatient not Found!!\n";
		}
		
		void update(int uid){
        cur = start;

        while(cur != NULL){
        if(cur->id == uid){

            string newName, newDisease;
            int newAge;

            cout<<"Enter New Name Age Disease: ";
            cin>>newName>>newAge>>newDisease;

            cur->name = newName;
            cur->age = newAge;
            cur->disease = newDisease;

            cout<<"Record Updated Successfully\n";
            return;
        }
        cur = cur->n;
    }

    cout<<"Patient not Found!!\n";
}
		
		void delete_patient(int uid){
			cur = start;
			temp = NULL;
			
			if (start == NULL){
				cout<<"List is empty!!\n";
				return;
			}
			
			if (start->id == uid && start->n == NULL){
				delete cur;
				start = NULL;
				cout<<"\nRecord delete Successfully\n";
				return;
			}
			
			if (start->id == uid ){
				start = start->n;
				start->p = NULL;
				delete cur;
				cout<<"\nRecord delete Successfully\n";
				return;
			}
			
			while (cur != NULL && cur->id != uid){
				temp = cur;
				cur = cur->n;
			}
			
			if (cur == NULL){
				cout<<"\nRecord not Found!!\n";
				return;
			}
			
			temp->n = cur->n;
			if(cur->n != NULL) cur->n->p = temp;
			
			delete cur;
			cout<<"\nRecord delete Successfully\n";
		}
		
		void display(){
			cur = start;
			cout<<"\n=============  Patient's Record   ==============\n\n";
			while(cur != NULL){
				cout<<"ID: "<<cur->id<<"\tName: "<<cur->name<<"\tAge: "<<cur->age<<"\t\tDisease: "<<cur->disease<<endl;
				cur = cur->n;
			}
		}
};

class doc_list{
	doctor *start,*cur,*temp;
	
	public:
		
		doc_list(){
			start = NULL;
			temp = NULL;
		}
		
		~doc_list(){
        cur = start;
        while(cur != NULL){
            temp = cur;
            cur = cur->n;
            delete temp;
        }
    }

    
    bool exists(int id){
        cur = start;
        while(cur != NULL){
            if(cur->id == id)
                return true;
            cur = cur->n;
        }
        return false;
    }
		
		bool isduplicate(int id){
		cur = start;
	        	while(cur != NULL){
			        if(cur->id == id){
			    	return true;
		    	} cur = cur->n;
		   }	
			return false;
		}
		
		void insert(int i,string s,string n){
			
			if(isduplicate(i)){
				cout<<"\nID must be unique!!\n";
				return;
			}
			
			if(start == NULL){
				start = new doctor;
				start->name = n;
				start->specialization = s;
				start->id = i;
				start->n = NULL;
				start->p = NULL;
			}
			
			else{
				cur = start;
				
				while(cur->n != NULL)
				     cur = cur->n;
				     
				temp = new doctor;
				temp->name = n;
				temp->specialization = s;
				temp->id = i;
				temp->n = NULL;
				temp->p = cur;
				cur->n = temp;
			}
		}
		
		void display(){
			cur = start;
			cout<<"\n=============  Doctor's Record   ==============\n\n";
			while(cur != NULL){
				cout<<"ID: "<<cur->id<<"\tName: "<<cur->name<<"\tspecialization: "<<cur->specialization<<endl;
				cur = cur->n;
			}
		}
};

class Billing {
public:
      void generateBill(int pid) {

        double consult = 1000;
        double treat = 2000;
        double med = 1500;

        double total = consult + treat + med;

        cout << "\n----- BILL -----\n";
        cout << "Patient ID: " << pid << endl;
        cout << "Consultation Fee: " << consult << endl;
        cout << "Treatment Charges: " << treat << endl;
        cout << "Medicine Charges: " << med << endl;
        cout << "Total Amount: " << total << endl;
        cout << "---------------\n";
    }
};

class appointmentQueue{
    appointment arr[100];
    int r,f;

public:
    appointmentQueue(){
        r = f = -1;    
    }

    void book(int pid, int did, string date){
        if(r == 99){
            cout<<"Queue Full\n";
            return;
        }

        if(f == -1)
            f = 0;

        r++;
        arr[r].pat_id = pid;
        arr[r].doc_id = did;
        arr[r].date = date;

        cout<<"Appointment booked successfully\n";
    }

    void attend(){
    	Billing billing;
    	
        if(f == -1 || f > r){
            cout<<"No appointments\n";
            return;
        }

        cout<<"Attending Patient ID: "
            <<arr[f].pat_id<<endl;
        billing.generateBill(arr[f].pat_id);
        f++;
        
        if(f > r){
            f = r = -1;
        }
    }

    void display(){
        if(f == -1 || f > r){
            cout<<"No appointments\n";
            return;
        }

        cout<<"\n==== Appointment List ====\n";
        for(int i = f; i <= r; i++){
            cout<<"Patient ID: "<<arr[i].pat_id
                <<" Doctor ID: "<<arr[i].doc_id
                <<" Date: "<<arr[i].date<<endl;
        }
    }
};



int main() {

    patientList patients;
    doc_list doctors;
    appointmentQueue appointments;
    Billing billing;

    int choice;

    do {
        cout << "\n========== HOSPITAL MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add Patient\n";
        cout << "2. Display Patients\n";
        cout << "3. Search Patient\n";
        cout << "4. Delete Patient\n";
        cout << "5. Add Doctor\n";
        cout << "6. Display Doctors\n";
        cout << "7. Book Appointment\n";
        cout << "8. Attend Patient\n";
        cout << "9. Display Appointments\n";
        cout << "10. Generate Bill\n";
        cout << "0. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {

            case 1: {
                int id, age;
                string name, disease;
                cout << "Enter Patient ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Disease: ";
                cin >> disease;
                patients.insert(id, age, disease, name);
                break;
            }

            case 2:
                patients.display();
                break;

            case 3: {
                int id;
                cout << "Enter Patient ID: ";
                cin >> id;
                patients.search(id);
                break;
            }

            case 4: {
                int id;
                cout << "Enter Patient ID: ";
                cin >> id;
                patients.delete_patient(id);
                break;
            }

            case 5: {
                int id;
                string name, spec;
                cout << "Enter Doctor ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Specialization: ";
                cin >> spec;
                doctors.insert(id, spec, name);
                break;
            }

            case 6:
                doctors.display();
                break;

            case 7: {
                int pid, did;
                string date;
                cout << "Enter PatientID: ";
                cin >> pid;
                cout << "Enter DoctorID: ";
                cin >> did;
                cout << "Enter Date: ";
                cin >> date;

                
                if (!patients.exists(pid)) {
                    cout << "Patient ID not found!\n";
                } else if (!doctors.exists(did)) {
                    cout << "Doctor ID not found!\n";
                } else {
                    appointments.book(pid, did, date);
                }
                break;
            }

            case 8:
                appointments.attend();
                break;

            case 9:
                appointments.display();
                break;

            case 10: {
                int pid;
                cout << "Enter Patient ID: ";
                cin >> pid;
                billing.generateBill(pid);
                break;
            }

            case 0:
                cout << "\nProgram Ended Successfully.\n";
                break;

            default:
                cout << "Invalid Choice! Try Again.\n";
                break;
        }

    } while(choice != 0);

    return 0;
}
