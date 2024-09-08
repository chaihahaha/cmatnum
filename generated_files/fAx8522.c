#include "fAx8522.h"

inline int fAx8522(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax8522.data[i][j] = 2*bmats.A_18_17.data[i][j] - 15*bmats.A_18_18.data[i][j] + 2*bmats.A_18_19.data[i][j] + 2*bmats.A_18_20.data[i][j] + 2*bmats.A_18_21.data[i][j] + 2*bmats.A_18_22.data[i][j] + 2*bmats.A_18_23.data[i][j] + 2*bmats.A_18_24.data[i][j] + 2*bmats.A_18_27.data[i][j] + 2*bmats.A_18_28.data[i][j] + 2*bmats.A_18_29.data[i][j] + 2*bmats.A_18_30.data[i][j] + 2*bmats.A_18_31.data[i][j] + 2*bmats.A_18_32.data[i][j];
        }
    }
    return 0;
}
