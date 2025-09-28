#include"Image_Class.h"
using namespace std;
void invert(Image &image){
    for (int i = 0; i < image.width; i++){
        for(int j=0;j<image.height;j++){
            image(i,j,0) = 255-image(i,j,0);
            image(i,j,1) = 255-image(i,j,1);
            image(i,j,2) = 255-image(i,j,2);
        }
    }
    cout<<"The filter has been applied successfully!\n";
}

void rotate(Image &image){
    cout<<"please enter the rotation degree : ";
    cout<<"1-90 / 2-180 / 3-270\n";
    int rotarion;
    cin>>rotarion;
    if(rotarion == 1){
        Image img2(image.height,image.width);
        for(int i=img2.width-1;i>=0;i--){
            for(int j=0;j<img2.height;j++){
                img2(i,j,0) = image(j,image.height-i-1,0);
                img2(i,j,1) = image(j,image.height-i-1,1);
                img2(i,j,2) = image(j,image.height-i-1,2);
            }
        }
        image=img2;
    }else if(rotarion == 2){
        Image img2(image.width,image.height);
        for(int i=img2.width-1;i>=0;i--){
            for(int j=img2.height-1;j>=0;j--){
                img2(i,j,0)= image(image.width-1-i,image.height-1-j,0);
                img2(i,j,1)= image(image.width-1-i,image.height-1-j,1);
                img2(i,j,2)= image(image.width-1-i,image.height-1-j,2);
            }
        }
        image=img2;
    }else if(rotarion == 3){
        Image img2(image.height,image.width);
        for(int i=0;i<img2.width;i++){
            for(int j=img2.height-1;j>=0;j--){
                img2(i,j,0)= image(image.width-1-j,i,0);
                img2(i,j,1)= image(image.width-1-j,i,1);
                img2(i,j,2)= image(image.width-1-j,i,2);
            }
        }
        image = img2;
    }
    cout<<"The filter has been applied successfully!\n";
}

int main(){
    string file_name, newfilename;
    cout<<"please enter your file name : ";
    cin>>file_name;
    Image image;
    try {
        bool loaded = image.loadNewImage(file_name);  
        if (loaded) {
            Image img(file_name);
            image=img;
            cout << "Image loaded successfully!\n";
        }
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << '\n';
    }
    while(true){
        cout<< "please enter a number from the following choices:\n";
        cout<<"1-Load a new image / 2-invert / 3-rotate / 4-save / 5-Exit\n";
        int choice;
        cin>>choice;
        if(choice == 1){
            cout<<"do you want to save the current one before loading a new one?\n";
            cout<<"1-yes / any other number is no\n";
            int y;
            cin>>y;
            if(y==1){
                cout<<"do you want to 1-save on the same file or 2-change file name\n";
                int x;
                cin>>x;
                if(x==1){
                    image.saveImage(file_name);
                }else if(x == 2){
                    cout<<"please enter the new file name : ";
                    cin>>newfilename;
                    try {
                        bool loaded = image.loadNewImage(newfilename);  
                        if (loaded) {
                            image.saveImage(newfilename);
                            cout<<"file saved successfully!\n";
                        }
                    } catch (const invalid_argument& e) {
                        cout << "Error: " << e.what() << '\n';
                    }
                }else{
                    cout<<"you enter the wrong number\n";
                }
            }else{
                cout<<"please enter the new image : ";
                cin>>file_name;
                try {
                    bool loaded = image.loadNewImage(file_name);  
                    if (loaded) {
                        Image img(file_name);
                        image=img;
                        cout << "Image loaded successfully!\n";
                    }
                } catch (const invalid_argument& e) {
                    cout << "Error: " << e.what() << '\n';
                }
            }
        }else if(choice == 2){
            invert(image);
        }else if(choice == 3){
            rotate(image);
        }else if(choice == 4){
            cout<< "please enter a number from the following choices:\n";
            cout<<"do you want to 1-save on the same file or 2-change file name\n";
            int x;
            cin>>x;
            if(x==1){
                image.saveImage(file_name);
            }else if(x == 2){
                cout<<"please enter the new file name : ";
                cin>>newfilename;
                try {
                    bool loaded = image.loadNewImage(newfilename);  
                    if (loaded) {
                        image.saveImage(newfilename);
                        cout<<"file saved successfully!\n";                        
                    }
                } catch (const invalid_argument& e) {
                    cout << "Error: " << e.what() << '\n';
                }
            }else{
                cout<<"you enter the wrong number\n";
            }
        }else if(choice == 5){
            break;
        }else{
            cout<<"you enter the wrong number\n";
        }
    }


    return 0;
}