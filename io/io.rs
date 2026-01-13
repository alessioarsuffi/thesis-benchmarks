use std::fs;

fn main() -> std::io::Result<()> {
    let data = fs::read("numeri.txt")?;

    let mut sum: u64 = 0;
    let mut x: u64 = 0;
    let mut in_num = false;

    for &b in &data {
        if (b'0'..=b'9').contains(&b) {
            x = x * 10 + (b - b'0') as u64;
            in_num = true;
        } else if in_num {
            sum += x;
            x = 0;
            in_num = false;
        }
    }
    if in_num {
        sum += x;
    }
    println!("Somma: {}", sum);
    Ok(())
}
