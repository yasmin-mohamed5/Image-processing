/*
    Project: Image Processing - Image Filters
    Section: 24

    Team Members:
    - Yasmin Mohamed (ID: 20240658) 
        Implemented: Rotate Filter, Invert Filter, frame Filter ,blur Filter , sunlight Filter.

    - Rawda Amr Mustafa (ID: 20240200) 
        Implemented: grey-scale, lighten_darken.

    - Salma Mohamed Mahmoud (ID: 20240241)
        Implemented: Black and White, Flip Image.    

Description:
    This file contains implementations of image filters 
    used in the project. The filters include:
        - Rotate: Rotates the image by 90/180/270 degrees.
        - Invert: Inverts the colors of the image (produces a negative effect).
        - Frame: Adds a decorative border to the image (Simple is blue, Fancy is white and red striped).
        - Blur: Softens the image by averaging neighboring pixels, with three levels of blur intensity (low, medium, and high) that control how smooth and hazy the result appears.
        -Sunlight: Brightens the image and adds a warm yellowish tone, simulating natural sunlight.
        - grey scale: Turns the image into shades of grey.
        - lighten_darken: adjusts the brightness to make the image lighter or darker.
        - Black and White: This filter converts an image into a pure black and white version with no gray shades.
        - Flip Image: This filter mirrors the image either horizontally or vertically.
    
*/



#include"Image_Class.h"
using namespace std;
#include<bits/stdc++.h>

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
    }else{
        cout<<"wrong input\n";
        return;
    }
    cout<<"The filter has been applied successfully!\n";
}

void frame(Image &image){
    cout<<"do you want a 1-simple or 2-fancy frame : ";
    int choice;
    cin>>choice;
    if(choice ==1){ // simple blue
        for(int i=0;i<image.width;i++){
            for (int j=0;j<16;j++){
                image(i,j,0)=0;
                image(i,j,1)=0;
                image(i,j,2)=255;
            }
        }
        for(int i=0;i<image.width;i++){
            for (int j=image.height-1;j>image.height-16;j--){
                image(i,j,0)=0;
                image(i,j,1)=0;
                image(i,j,2)=255;
            }
        }
        for(int i=0;i<16;i++){
            for (int j=0;j<image.height;j++){
                image(i,j,0)=0;
                image(i,j,1)=0;
                image(i,j,2)=255;
            }
        }
        for(int i=image.width-1;i>image.width-16;i--){
            for (int j=0; j<image.height;j++){
                image(i,j,0)=0;
                image(i,j,1)=0;
                image(i,j,2)=255;
            }
        }
    }else if(choice == 2){ // fancy red & white
        for(int i=0;i<image.width;i++){
            for (int j=0;j<16;j++){
                if((i/20)%2==0){
                    image(i,j,0)=255;
                    image(i,j,1)=0;
                    image(i,j,2)=0;
                }else{
                    image(i,j,0)=255;
                    image(i,j,1)=255;
                    image(i,j,2)=255;
                }
            }
        }
        for(int i=0;i<image.width;i++){
            for (int j=image.height-1;j>image.height-16;j--){
                if((i/20)%2==0){
                    image(i,j,0)=255;
                    image(i,j,1)=0;
                    image(i,j,2)=0;
                }else{
                    image(i,j,0)=255;
                    image(i,j,1)=255;
                    image(i,j,2)=255;
                }
                
            }
        }
        for(int i=0;i<16;i++){
            for (int j=0;j<image.height;j++){
                if((j/20)%2==0){
                    image(i,j,0)=255;
                    image(i,j,1)=0;
                    image(i,j,2)=0;
                }else{
                    image(i,j,0)=255;
                    image(i,j,1)=255;
                    image(i,j,2)=255;
                }
            }
        }
        for(int i=image.width-1;i>image.width-16;i--){
            for (int j=0; j<image.height;j++){
                if((j/20)%2==0){
                    image(i,j,0)=255;
                    image(i,j,1)=0;
                    image(i,j,2)=0;
                }else{
                    image(i,j,0)=255;
                    image(i,j,1)=255;
                    image(i,j,2)=255;
                }
            }
        }
    }else{
        cout<<"wrong input \n";
        return;
    }
    cout<<"The filter has been applied successfully!\n";
} 

void blur(Image &image){
    Image img=image;
    cout<<"enter the Blur intensity: 1-low / 2-medium / 3-high : ";
    int intensity;
    cin>>intensity;
    if(intensity == 1){
        int rad=1;
        for(int i=0;i<image.width;i++){
            for(int j=0;j<image.height;j++){
                double r=0,g=0,b=0,count=0;
                for(int x=-rad;x<rad;x++){
                    for (int y=-rad;y<rad;y++){
                        int new_x=i+x;
                        int new_y=j+y;
                        if(new_x<0 || new_y<0 || new_x>=image.width || new_y>=image.height){
                            continue;
                        } 
                        r+=img(new_x,new_y,0);
                        g+=img(new_x,new_y,1);
                        b+=img(new_x,new_y,2);
                        count++;
                    }
                }
                r/=count;
                g/=count;
                b/=count;
                image(i,j,0)=r;
                image(i,j,1)=g;
                image(i,j,2)=b;
            }
        }
    }else if(intensity == 2){
        int rad=3;
        for(int i=0;i<image.width;i++){
            for(int j=0;j<image.height;j++){
                double r=0,g=0,b=0,count=0;
                for(int x=-rad;x<rad;x++){
                    for (int y=-rad;y<rad;y++){
                        int new_x=i+x;
                        int new_y=j+y;
                        if(new_x<0 || new_y<0 || new_x>=image.width || new_y>=image.height){
                            continue;
                        } 
                        r+=img(new_x,new_y,0);
                        g+=img(new_x,new_y,1);
                        b+=img(new_x,new_y,2);
                        count++;
                    }
                }
                r/=count;
                g/=count;
                b/=count;
                image(i,j,0)=r;
                image(i,j,1)=g;
                image(i,j,2)=b;
            }
        }
    }else if(intensity == 3){
        int rad=5;
        for(int i=0;i<image.width;i++){
            for(int j=0;j<image.height;j++){
                double r=0,g=0,b=0,count=0;
                for(int x=-rad;x<rad;x++){
                    for (int y=-rad;y<rad;y++){
                        int new_x=i+x;
                        int new_y=j+y;
                        if(new_x<0 || new_y<0 || new_x>=image.width || new_y>=image.height){
                            continue;
                        } 
                        r+=img(new_x,new_y,0);
                        g+=img(new_x,new_y,1);
                        b+=img(new_x,new_y,2);
                        count++;
                    }
                }
                r/=count;
                g/=count;
                b/=count;
                image(i,j,0)=r;
                image(i,j,1)=g;
                image(i,j,2)=b;
            }
        }
    }else{
        cout<<"wrong input\n";
        return;
    }
    
    cout<<"The filter has been applied successfully!\n";
}

void sunlight(Image &image){
    for(int i=0;i<image.width;i++){
        for(int j=0;j<image.height;j++){
            image(i,j,0)=min(image(i,j,0)*1.3,255.0);
            image(i,j,1)=min(image(i,j,1)*1.2,255.0);
            image(i,j,2)*=0.8;
        }
    }
    cout<<"The filter has been applied successfully!\n";
}

void grey_scale(Image &image){
        for (int i=0; i<image.width;i++){
        for (int j=0; j<image.height;j++){
            unsigned int avrege=0;
            for (int k=0;k<3;k++){
                avrege+=image(i,j,k);
            }
            avrege=avrege/3;
            image(i,j,0)=avrege;
            image(i,j,1)=avrege;
            image(i,j,2)=avrege;
        }
    }
    cout<<"The filter has been applied successfully!\n"; 
}
void darken_lighten(Image &image){
    string choice;
    cout<<"darken or lighten?\n";
    cin>>choice;
    if(choice=="darken"){
        for(int i=0; i<image.width; i++){
        for(int j=0;j< image.height; j++){
            for(int k=0; k<3;k++){
                double pix= image(i,j,k)*0.5;
                if(pix>255){
                    pix=255;
                }else if(pix<0){
                    pix=0;
                }
                image(i,j,k)=pix;
            }
        }
    }
    }else if(choice=="lighten"){
        for(int i=0; i<image.width; i++){
        for(int j=0;j< image.height; j++){
            for(int k=0; k<3;k++){
                double pix= image(i,j,k)*1.5;
                if(pix>255){
                    pix=255;
                }else if(pix<0){
                    pix=0;
                }
                image(i,j,k)=pix;
            }
        }
    }}else{
        cout<<"wrong";
        return;
    }
    cout<<"The filter has been applied successfully!\n";
}

void black_and_white(Image &image){
    for(int i =0 ;i<image.width; i++){
        for(int j=0;j<image.height ;j++){
            int threshold=128;

            int r =image(i,j,0);
            int g=image(i ,j,1);
            int b= image(i,j,2);

            int gray = (r+g+b)/3;
            if(gray>=threshold){
                image(i,j,0)=255;
                image(i,j,1)=255;
                image(i,j,2)=255;
            }
            else{
                image(i,j,0)=0;
                image(i,j,1)=0;
                image(i,j,2)=0;
            }
        }
    }
    cout<<"The filter has been applied successfully!\n";
}

void Flip_image(Image &image){
    char type;
    cout<<"enter the type h-horizontal Or v-vertical: ";
    cin>>type;
    if(type =='h'){
        for(int i=0;i<image.width/2;i++){
        for(int j=0;j<image.height;j++){
            for(int c=0;c<3;c++){
                int values = image(i,j,c);
                image(i,j,c)=image(image.width-1-i,j,c);
                image(image.width-1-i,j,c)=values;
            }     
        }
    }
    
    cout<<"H filpapplied successfully!\n";
    }
    else if(type =='v'){
        for(int i=0;i<image.width;i++){
            for(int j=0;j<image.height/2;j++){
                for(int c=0;c<3;c++){
                    int values=image(i,j,c);
                    image(i,j,c)=image(i,image.height-1-j,c);
                    image(i,image.height-1-j,c)=values;
                }
            }
        }
        cout<<"v flip applied successfully! \n";
    }
    
}
void Crop_image(Image &image){
    int x;
    cout<< "x-enter the horizontal point. \n";
    cin >> x;
    int y;
    cout<<"y-enter the vertical point. \n";
    cin >> y;
    int new_width , new_height;
    cout <<"enter new_width and new_height. \n ";
    cin>> new_width >> new_height;

    if(x+new_width>image.width || y+new_height>image.height){
        cout<<"Dimensions are larger than the original image dimensions.\n ";
    }
    else{
     Image cropped_image(new_width,new_height);

     for(int i=0;i<new_width;i++){
        for(int j=0;j<new_height;j++){
            for(int c=0;c<3;c++){
                cropped_image(i,j,c)=image(x+i,y+j,c); 
            }
          }
        }
        image=cropped_image;
     }
     
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
        cout<<"1-Load a new image / 2-invert / 3-rotate / 4-grey_scale / 5-darken_lighten / 6-black_and_white /\n 7-flip_image / 8-frame / 9-Crop_image / 10-blur / 11-sunlight / 12-save / 13-exit\n";
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
                    cout<<"image savesd successfully\n";
                }else if(x == 2){
                    cout<<"please enter the new file name : ";
                    cin>>newfilename;
                    try{
                        bool save = image.saveImage(newfilename);
                        if(save){
                            image.saveImage(newfilename);
                            cout<<"image savesd successfully\n";
                        }
                    }
                    catch(const invalid_argument& e){
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
        }else if(choice ==4){
            grey_scale(image);
        }else if(choice ==5){
            darken_lighten(image);
        }else if(choice ==6){
            black_and_white(image);
        }else if(choice ==7){
            Flip_image(image);
        }else if(choice ==8){
            frame(image);
        }else if(choice==9){
            Crop_image(image);
        }else if(choice == 10){
            blur(image);
        }else if(choice == 11){
            sunlight(image);
        }
        else if(choice == 12){
            cout<< "please enter a number from the following choices:\n";
            cout<<"do you want to 1-save on the same file or 2-change file name\n";
            int x;
            cin>>x;
            if(x==1){
                image.saveImage(file_name);
                cout<<"image savesd successfully\n";
            }else if(x == 2){
                cout<<"please enter the new file name : ";
                cin>>newfilename;
                try{
                    bool save = image.saveImage(newfilename);
                    if(save){
                        image.saveImage(newfilename);
                    cout<<"image savesd successfully\n";
                    }
                }
                catch(const invalid_argument& e){
                    cout << "Error: " << e.what() << '\n';
                }
            }else{
                cout<<"you enter the wrong number\n";
            }
        }else if(choice == 13){
            cout<<"do you want to save the image before exit\n";
            cout<<"1-yes / any number-no : ";
            int y;
            cin>>y;
            if(y==1){
                cout<< "please enter a number from the following choices:\n";
                cout<<"do you want to 1-save on the same file or 2-change file name\n";
                int x;
                cin>>x;
                if(x==1){
                    image.saveImage(file_name);
                    cout<<"image savesd successfully\n";
                }else if(x == 2){
                    cout<<"please enter the new file name : ";
                    cin>>newfilename;
                    try{
                        bool save = image.saveImage(newfilename);
                        if(save){
                            image.saveImage(newfilename);
                            cout<<"image savesd successfully\n";
                        }
                    }catch(const invalid_argument& e){
                        cout << "Error: " << e.what() << '\n';
                    }
                }
            }
            break;
        }else{
            cout<<"you enter the wrong number\n";
        }
    }
    return 0;
}