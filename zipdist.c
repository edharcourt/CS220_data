#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Debug
    // printf("%d %s %s %s\n", argc, argv[0], argv[1], argv[2]);
    
    // Information for each zipcode
    char state1[3], state2[3], city1[30], city2[30];
    double lat1, lon1, lat2, lon2;

    // temp variables for reading
    char code[6], tstate[3], tcity[30];
    double tlat, tlon;

    // What can go wrong?
    FILE *f = fopen("zips.csv", "r");
 
    if (f == NULL) {
        printf("Error: could not open zips.csv\n");
        return 1;
    }

    int got = 0; // number of zipcodes found
    
    // TODO Add logi to quit at end of file
    while (got != 2) {

        // What can go wrong?  Poorly formatted file
        int eof = fscanf(f, "%5s,%2s,%[^,],%lf,%lf",
		   code, tstate, tcity, &tlat, &tlon);

        if (eof == EOF) 
            break;
            
        // TODO DRY - don't repeat yourself
        // Refactoring 
        if (strcmp(argv[1],code) == 0) {
            strcpy(state1, tstate);  
            strcpy(city1, tcity);  
            lat1 = tlat;
            lon1 = tlon;
            got++;
        }	

        if (strcmp(argv[2],code) == 0) {
            strcpy(state2, tstate);  
            strcpy(city2, tcity);  
            lat2 = tlat;
            lon2 = tlon;
            got++;
        }	
    } // while
    printf("%s %s, %s, (Latitude) %lf, (Longitude) %lf\n", 
            argv[1], city1, state1, lat1, lon1);  
    printf("%s %s, %s, (Latitude) %lf, (Longitude) %lf\n", 
            argv[2], city2, state2, lat2, lon2);  

} // main
