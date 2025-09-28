#include<iostream>
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
}

void rotate(Image &image){
    cout<<"please enter the rotation degree : ";
    int rotarion;
    cin>>rotarion;
    if(rotarion == 90){
        Image img2(image.height,image.width);
        for(int i=img2.width-1;i>=0;i--){
            for(int j=0;j<img2.height;j++){
                img2(i,j,0) = image(j,image.height-i-1,0);
                img2(i,j,1) = image(j,image.height-i-1,1);
                img2(i,j,2) = image(j,image.height-i-1,2);
            }
        }
        image=img2;
    }else if(rotarion == 180){
        Image img2(image.width,image.height);
        for(int i=img2.width-1;i>=0;i--){
            for(int j=img2.height-1;j>=0;j--){
                img2(i,j,0)= image(image.width-1-i,image.height-1-j,0);
                img2(i,j,1)= image(image.width-1-i,image.height-1-j,1);
                img2(i,j,2)= image(image.width-1-i,image.height-1-j,2);
            }
        }
        image=img2;
    }else if(rotarion == 270){
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

}
void grey_scale(Image &image){
    
}

int main(){
    string file_name, new_filename,filter;
    // cout<<"please enter your file name : ";
    // cin>>file_name;
    Image image("D:/image filters/Image-processing/images/luffy.jpg");
    cout<<"avilable filters : invert / rotate\n";
    cout<<"please enter your filter : ";
    cin>>filter;
    if(filter == "invert"){
        invert(image);
    }else if(filter == "rotate"){
        rotate(image);
    }
    // cout<<"please enter your new file name : ";
    // cin>>new_filename;
    image.saveImage("D:/image filters/Image-processing/images/new_luffy.png");

    return 0;
}