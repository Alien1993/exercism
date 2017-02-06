DNA = 'GCTA'
RNA = 'CGAU'


def to_rna(strand):
    result = []
    for nucleotide in strand:
        i = DNA.find(nucleotide)
        if i == -1:
            return ''
        result.append(RNA[i])
    return "".join(result)
