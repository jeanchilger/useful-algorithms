def expandMatrix(mat, times=1, e=None):
    """
    Expands the matrix from the outside, as many times as necessary.
    The elements added due to the expansion are None by default.
    """
    mat2 = [row[:] for row in mat]

    line = [e for i in range(len(mat2[0]) + (times*2))]
    for v in range(times):
        mat2.insert(0, line)
        mat2.append(line)

    for i in range(times, len(mat2)-times):
        for v in range(times):
            mat2[i].insert(0, e)
            mat2[i].append(e)

    return mat2
