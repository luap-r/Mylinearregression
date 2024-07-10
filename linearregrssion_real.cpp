#include<iostream>

int sizeofarray(float points[][2]){
    return 15;
}

float sum_x(float points[][2]){

    //int points_size = *(&points + 1) - points;
    int points_size = sizeofarray(points);
    float sum = 0;


    for(int i = 0 ; i < points_size ; i++){
        sum += points[i][0];
    }

    return sum;
}

float sum_y(float points[][2]){

    //int points_size = *(&points + 1) - points;
    int points_size = sizeofarray(points);
    float sum = 0;


    for(int i = 0 ; i < points_size ; i++){
        sum += points[i][1];
    }

    return sum;
}

float sum_x_sqre(float points[][2]){

    //int points_size = *(&points + 1) - points;
    int points_size = sizeofarray(points);
    float sum = 0;


    for(int i = 0 ; i < points_size ; i++){
        sum += points[i][0]*points[i][0];
    }

    return sum;
}

float sum_y_sqre(float points[][2]){

    //int points_size = *(&points + 1) - points;
    int points_size = sizeofarray(points);
    float sum = 0;


    for(int i = 0 ; i < points_size ; i++){
        sum += points[i][1]*points[i][1];
    }

    return sum;
}

float sum_xy(float points[][2]){

    //int points_size = *(&points + 1) - points;
    int points_size = sizeofarray(points);
    float sum = 0;


    for(int i = 0 ; i < points_size ; i++){
        sum += points[i][0]*points[i][1];
    }

    return sum;
}

float *make_linearregression(float points[][2]){
    
    static float curve[2] = {0,0};

    int pc_n = sizeofarray(points);

    // curve[0] = ((count_points*sum_xy(points))-(sum_x(points)*sum_y(points))) /
    //            ((count_points*sum_x_sqre(points))-(sum_x_sqre(points)*sum_x_sqre(points)));

    // std::cout << curve[0] << std::endl;

    // curve[1] = (sum_y(points)*sum_x_sqre(points)-sum_x(points)*sum_xy(points)) / (count_points*sum_x_sqre(points)-sum_x(points)*sum_x_sqre(points));

    float sum_x_ = sum_x(points);
    float sum_y_ = sum_y(points);
    float sum_xy_ = sum_xy(points);
    float sum_x_sqre_ = sum_x_sqre(points);
    float sum_y_sqre_ = sum_y_sqre(points);
    float sum_x_sqre_a = sum_x(points)*sum_x(points);



    curve[0] = (pc_n*sum_xy_-sum_x_*sum_y_) / (pc_n*sum_x_sqre_-sum_x_sqre_a);

    curve[1] = (sum_y_*sum_x_sqre_-sum_x_*sum_xy_) / (pc_n*sum_x_sqre_-sum_x_sqre_a);


    return curve;
}

float err(){
    
}

int main(){

    float points[][2] = {{1.47,52.21}, 
                        {1.5,53.12},
                        {1.52,54.48},
                        {1.55,55.84},
                        {1.57,57.2},
                        {1.60,58.57},
                        {1.63,59.93},
                        {1.65,61.29},
                        {1.68,63.11},
                        {1.70,64.47},
                        {1.73,66.28},
                        {1.75,68.10},
                        {1.78,69.92},
                        {1.80,72.19},
                        {1.83,74.46}};

    // float points[][2] = {{0,0}, {1,1}, {2,2}, {3,3}};

    float *result = make_linearregression(points);

    // std::cout << sum_x(points) << std::endl;
    // std::cout << sum_y(points) << std::endl;
    // std::cout << sum_x_sqre(points) << std::endl;
    // std::cout << sum_y_sqre(points) << std::endl;
    // std::cout << sum_xy(points) << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "y = " << result[0] << "x " << result[1] << std::endl;

    std::cout << "\n" << std::endl;


}