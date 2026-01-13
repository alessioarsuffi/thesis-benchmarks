use std::fs;

fn main() -> std::io::Result<()> {
    let data = fs::read("numeri_float.txt")?;

    let mut sum: f64 = 0.0;

    let mut sign: f64 = 1.0;
    let mut int_part: u64 = 0;
    let mut frac_part: u64 = 0;
    let mut frac_div: f64 = 1.0;

    let mut in_num = false;
    let mut in_frac = false;

    for &b in &data {
        match b {
            b'-' if !in_num => {
                sign = -1.0;
            }
            b'0'..=b'9' => {
                in_num = true;
                let d = (b - b'0') as u64;
                if !in_frac {
                    int_part = int_part * 10 + d;
                } else {
                    frac_part = frac_part * 10 + d;
                    frac_div *= 10.0;
                }
            }
            b'.' if in_num && !in_frac => {
                in_frac = true;
            }
            _ => {
                if in_num {
                    let value = sign * (int_part as f64 + (frac_part as f64) / frac_div);
                    sum += value;

                    sign = 1.0;
                    int_part = 0;
                    frac_part = 0;
                    frac_div = 1.0;
                    in_num = false;
                    in_frac = false;
                } else {
                    sign = 1.0;
                }
            }
        }
    }

    if in_num {
        let value = sign * (int_part as f64 + (frac_part as f64) / frac_div);
        sum += value;
    }

    println!("Somma: {:.6}", sum);
    Ok(())
}
