#ifndef CMAP_H
#define CMAP_H
#include <iostream>
/*!
 *\ brief The cmap class
 */
class cmap
{
    public:
        cmap();
        char map[21][51] = {
"##################################################", // 0
"#                                                #", // 1
"#     ############          ###############      #", // 2
"#     #          #          #             #      #", // 3
"#     #          #          #             #      #", // 4
"#     ############          ###############      #", // 5
"#                                                #", // 6
"#                   ######                       #", // 7
"#                   #    #           #####       #", // 8
"#                   #    #           #   #       #", // 9
"#                   #    #           #   #       #", // 10
"#                   #    #           #   #       #", // 11
"#                   ######           #   #       #", // 12
"#                                    #####       #", // 13
"#    #########                                   #", // 14
"#    #       #         ################          #", // 15
"#    #       #         #              #          #", // 16
"#    #########         ################          #", // 17
"#                                                #", // 18
"##################################################"
};
        /*!
        *\ brief This function is for showing map
        */
    void ShowMap();
     /*!
        *\ brief This function is for counting created objects
        */
    static int totalObjects(void)
    {
        return count;
    }
        ~cmap();

    protected:

    private:
    static int count;
};

#endif // CMAP_H
