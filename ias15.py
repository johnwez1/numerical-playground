#gauss_radau_spacings, from everhart 1985 paper
hs = [
    0.0,
    0.05626256053692215,
    0.18024069173689236,
    0.35262471711316964,
    0.54715362633055538,
    0.73421017721541053,
    0.88532094683909577,
    0.97752061356128750,
    1.0
]

#the number of hs is determinined by the desired truncation but is vice versa in this code
truncation_order = len(hs) - 1

#constants in equations
cs = [[0 for i in range(truncation_order)] for i in range(truncation_order)]
ds = [[0 for i in range(truncation_order)] for i in range(truncation_order)]
rs = [[0 for i in range(truncation_order + 1)] for i in range(truncation_order + 1)]

#init the changing B, G and F arrays
Bs = [0 for i in range(truncation_order)]
Gs = [0 for i in range(truncation_order)]
Fs = [0 for i in range(truncation_order + 1)] #note the extra term

for j in range(truncation_order):
    for k in range(j + 1): #k <= j (including the k = j case implicitly)

        if j == k:
            cs[j][k] = 1
            ds[j][k] = 1
        elif j > 0 and k == 0:
            cs[j][0] = -hs[j] * cs[j-1][0]
            ds[j][0] = hs[1] * ds[j-1][0]
            rs[j][k] = 1/(hs[j])
        else:
            cs[j][k] = cs[j-1][k-1] - hs[j] * cs[j-1][k]
            ds[j][k] = ds[j-1][k-1] + hs[k + 1] * ds[j-1][k]
            rs[j][k] = 1/(hs[j]-hs[k])

def update_Gs_from_Fs(current_truncation_order):
    
    if current_truncation_order == 0:
        Gs[0] = (Fs[1] - Fs[0]) * rs[1][0]
    
    if current_truncation_order == 1: 
        Gs[1] = ((Fs[2] - Fs[0]) * rs[2][0] - Gs[0]) * rs[2][1]
    
    if current_truncation_order == 2: 
        Gs[2] = (((Fs[3] - Fs[0]) * rs[3][0] - Gs[0]) * rs[3][1] - Gs[1]) * rs[3][2]
    
    if current_truncation_order == 3: 
        Gs[3] = ((((Fs[4] - Fs[0]) * rs[4][0] - Gs[0]) * rs[4][1] - Gs[1]) * rs[4][2] - Gs[2]) * rs[4][3]
    
    if current_truncation_order == 4: 
        Gs[4] = (((((Fs[5] - Fs[0]) * rs[5][0] - Gs[0]) * rs[5][1] - Gs[1]) * rs[5][2] - Gs[2]) * rs[5][3] - Gs[3]) * rs[5][4]
    
    if current_truncation_order == 5: 
        Gs[5] = ((((((Fs[6] - Fs[0]) * rs[6][0] - Gs[0]) * rs[6][1] - Gs[1]) * rs[6][2] - Gs[2]) * rs[6][3] - Gs[3]) * rs[6][4] - Gs[4]) * rs[6][5]

    if current_truncation_order == 6: 
        Gs[6] = (((((((Fs[7] - Fs[0]) * rs[7][0] - Gs[0]) * rs[7][1] - Gs[1]) * rs[7][2] - Gs[2]) * rs[7][3] - Gs[3]) * rs[7][4] - Gs[4]) * rs[7][5] - Gs[5]) * rs[7][6]

    if current_truncation_order == 7:     
        Gs[7] = ((((((((Fs[8] - Fs[0]) * rs[8][0] - Gs[0]) * rs[8][1] - Gs[1]) * rs[8][2] - Gs[2]) * rs[8][3] - Gs[3]) * rs[8][4] - Gs[4]) * rs[8][5] - Gs[5]) * rs[8][6] - Gs[6]) * rs[8][7]

def update_Gs_from_Bs(current_truncation_order):
    #the series is currently truncated by the h_n step position so values are updated at that point only
    
    Gs[0] = ds[0][0] * Bs[0] + ds[1][0] * Bs[1] + ds[2][0] * Bs[2] + ds[3][0] * Bs[3] + ds[4][0] * Bs[4] + ds[5][0] * Bs[5] + ds[6][0] * Bs[6] + ds[7][0] * Bs[7]
    if current_truncation_order == 0: return
    Gs[1] =                    ds[1][1] * Bs[1] + ds[2][1] * Bs[2] + ds[3][1] * Bs[3] + ds[4][1] * Bs[4] + ds[5][1] * Bs[5] + ds[6][1] * Bs[6] + ds[7][1] * Bs[7]
    if current_truncation_order == 1: return
    Gs[2] =                                       ds[2][2] * Bs[2] + ds[3][2] * Bs[3] + ds[4][2] * Bs[4] + ds[5][2] * Bs[5] + ds[6][2] * Bs[6] + ds[7][2] * Bs[7]
    if current_truncation_order == 2: return
    Gs[3] =                                                          ds[3][3] * Bs[3] + ds[4][3] * Bs[4] + ds[5][3] * Bs[5] + ds[6][3] * Bs[6] + ds[7][3] * Bs[7]
    if current_truncation_order == 3: return
    Gs[4] =                                                                             ds[4][4] * Bs[4] + ds[5][4] * Bs[5] + ds[6][4] * Bs[6] + ds[7][4] * Bs[7]
    if current_truncation_order == 4: return
    Gs[5] =                                                                                                ds[5][5] * Bs[5] + ds[6][5] * Bs[5] + ds[7][5] * Bs[7]
    if current_truncation_order == 5: return
    Gs[6] =                                                                                                                   ds[6][6] * Bs[6] + ds[7][6] * Bs[7]
    if current_truncation_order == 6: return
    Gs[7] =                                                                                                                                      ds[7][7] * Bs[7]

def update_Bs_from_Gs(current_truncation_order):
    #the series is currently truncated by the h_n step position so values are updated at that point only

    Bs[0] = cs[0][0] * Gs[0] + cs[1][0] * Gs[1] + cs[2][0] * Gs[2] + cs[3][0] * Gs[3] + cs[4][0] * Gs[4] + cs[5][0] * Gs[5] + cs[6][0] * Gs[6] + cs[7][0] * Gs[7]
    if current_truncation_order == 0: return
    Bs[1] =                    cs[1][1] * Gs[1] + cs[2][1] * Gs[2] + cs[3][1] * Gs[3] + cs[4][1] * Gs[4] + cs[5][1] * Gs[5] + cs[6][1] * Gs[6] + cs[7][1] * Gs[7]
    if current_truncation_order == 1: return
    Bs[2] =                                       cs[2][2] * Gs[2] + cs[3][2] * Gs[3] + cs[4][2] * Gs[4] + cs[5][2] * Gs[5] + cs[6][2] * Gs[6] + cs[7][2] * Gs[7]
    if current_truncation_order == 2: return
    Bs[3] =                                                          cs[3][3] * Gs[3] + cs[4][3] * Gs[4] + cs[5][3] * Gs[5] + cs[6][3] * Gs[6] + cs[7][3] * Gs[7]
    if current_truncation_order == 3: return
    Bs[4] =                                                                             cs[4][4] * Gs[4] + cs[5][4] * Gs[5] + cs[6][4] * Gs[6] + cs[7][4] * Gs[7]
    if current_truncation_order == 4: return
    Bs[5] =                                                                                                cs[5][5] * Gs[5] + cs[6][5] * Gs[5] + cs[7][5] * Gs[7]
    if current_truncation_order == 5: return
    Bs[6] =                                                                                                                   cs[6][6] * Gs[6] + cs[7][6] * Gs[7]
    if current_truncation_order == 6: return
    Bs[7] =                                                                                                                                      cs[7][7] * Gs[7]

def next_sequence_Bs(Q):
    #Q is the ratio of T_new/T_old
    #using the binomial coefficients on the diagonal
    Bs[0] = (Q**1) * (Bs[0] + 2 * Bs[1] + 3 * Bs[2] + 4 * Bs[3] + 5 * Bs[4] + 6 * Bs[5] + 7 * Bs[6])
    Bs[1] = (Q**2) * (Bs[1] + 3 * Bs[2] + 6 * Bs[3] + 10 * Bs[4] + 15 * Bs[5] + 21 * Bs[6])
    Bs[2] = (Q**3) * (Bs[2] + 4 * Bs[3] + 10 * Bs[4] + 20 * Bs[5] + 35 * Bs[6])
    Bs[3] = (Q**4) * (Bs[3] + 5 * Bs[4] + 15 * Bs[5] + 35 * Bs[6])
    Bs[4] = (Q**5) * (Bs[4] + 6 * Bs[5] + 21 * Bs[6])
    Bs[5] = (Q**6) * (Bs[5] + 7 * Bs[6])
    Bs[6] = (Q**7) * (Bs[6])

#we only really need this function with h_n = 1 for orbital dynamics, since we only require the velocity as an initial condition for the next sequence
def get_current_velocity(h_n, T):
    return (init_velocity + h_n * T * 
    (Fs[0] + h_n * 
    (Bs[0]/2 + h_n * 
    (Bs[1]/3 + h_n * 
    (Bs[2]/4 + h_n * 
    (Bs[3]/5 + h_n * 
    (Bs[4]/6 + h_n * 
    (Bs[5]/7 + h_n * 
    (Bs[6]/8 + h_n * 
    (Bs[7]/9
    ))))))))))

def get_current_position(h_n, T):
    #the coefficient pattern here is from double integration, 2 * 1 = 2, 3 * 2 = 6, 4 * 3 = 12 etc
    return (init_position
     + (init_velocity * h_n * T) 
     + ((h_n * T)**2) * 
     (Fs[0]/2 + h_n * 
     (Bs[0]/6 + h_n * 
     (Bs[1]/12 + h_n * 
     (Bs[2]/20 + h_n * 
     (Bs[3]/30 + h_n * 
     (Bs[4]/42 + h_n * 
     (Bs[5]/56 + h_n * 
     (Bs[6]/72 + h_n * 
     (Bs[7]/90)
     )))))))))

#create a dummy force        
def force(x):
    return -x

#initial conditions
init_position = 5
init_velocity = 0

running_time = 100

#main procedure
# find the force acting on partical, given initial position, this is F[0]
# at each substep, give the updated F values

#loop will implictly start with this:
#Fs[0] = force(init_position)

positions = [init_position]

print(Bs)
#6 is just because
for i in range(6):
    for substep in range(len(hs)):
        substep_position = get_current_position(hs[substep], 0.001)

        Fs[substep] = force(substep_position)

        update_Gs_from_Fs(substep)
        update_Bs_from_Gs(substep)

#update the values
init_position = get_current_position(1, 0.001)
positions.append(init_position)
init_velocity = get_current_velocity(1, 0.001)
next_sequence_Bs(1)

#now repeat for some time
#take Q = 1 as a test

for t in range(10000):
    for i in range(2):
        for substep in range(len(hs)):
            substep_position = get_current_position(hs[substep], 0.001)

            Fs[substep] = force(substep_position)

            update_Gs_from_Fs(substep)
            update_Bs_from_Gs(substep)

    #update the values
    init_position = get_current_position(1, 0.001)
    positions.append(init_position)
    init_velocity = get_current_velocity(1, 0.001)
    next_sequence_Bs(1)

import matplotlib.pyplot as plt

plt.plot(positions)
plt.show()
print("done.")