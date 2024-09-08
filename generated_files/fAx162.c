#include "fAx162.h"

inline int fAx162(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax162.data[i][j] = bmats.A_2_12.data[i][j] + bmats.A_2_13.data[i][j] + bmats.A_2_14.data[i][j] + bmats.A_2_15.data[i][j] + bmats.A_2_16.data[i][j] + bmats.A_2_19.data[i][j] + bmats.A_2_20.data[i][j] + bmats.A_2_21.data[i][j] + bmats.A_2_22.data[i][j];
        }
    }
    return 0;
}
