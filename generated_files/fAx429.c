#include "fAx429.h"

inline int fAx429(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax429.data[i][j] = bmats.A_2_17.data[i][j] + bmats.A_2_18.data[i][j] + bmats.A_2_19.data[i][j] + bmats.A_2_20.data[i][j] + bmats.A_2_21.data[i][j] + bmats.A_2_22.data[i][j] + bmats.A_2_23.data[i][j] + bmats.A_2_24.data[i][j] + bmats.A_2_25.data[i][j] + bmats.A_2_26.data[i][j] + bmats.A_2_27.data[i][j] + bmats.A_2_28.data[i][j] + bmats.A_2_31.data[i][j] + bmats.A_2_32.data[i][j];
        }
    }
    return 0;
}
