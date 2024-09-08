#include "fAx191.h"

inline int fAx191(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax191.data[i][j] = -bmats.A_7_14.data[i][j] - bmats.A_7_15.data[i][j] - bmats.A_7_16.data[i][j] - bmats.A_7_17.data[i][j] - bmats.A_7_18.data[i][j] - bmats.A_7_19.data[i][j] - bmats.A_7_20.data[i][j] - bmats.A_7_21.data[i][j] - bmats.A_7_22.data[i][j] + bmats.Ax115.data[i][j];
        }
    }
    return 0;
}
