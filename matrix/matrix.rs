const N: usize = 2500;

fn idx(r: usize, c: usize) -> usize {
    r * N + c
}
fn matrix_product(a: &[f64], b: &[f64], c: &mut [f64]) {
    c.fill(0.0);

    for i in 0..N {
        for k in 0..N {
            let aik = a[idx(i, k)];
            let bk_row = k * N;
            let ci_row = i * N;

            for j in 0..N {
                c[ci_row + j] += aik * b[bk_row + j];
            }
        }
    }
}

fn main() {
    let mut a = vec![0.0_f64; N * N];
    let mut b = vec![0.0_f64; N * N];
    let mut c = vec![0.0_f64; N * N];

    for i in 0..N {
        for j in 0..N {
            a[idx(i, j)] = (i as f64) + 0.01 * (j as f64);
            b[idx(i, j)] = (j as f64) - 0.02 * (i as f64);
        }
    }

    matrix_product(&a, &b, &mut c);

    let c00 = c[idx(0, 0)];
    let c99 = c[idx(99, 99)];

    println!("C[0,0]   = {c00}");
    println!("C[99,99] = {c99}");
}
