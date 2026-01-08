fn fib_iterative(n: i32) -> u64 {
    if n <= 1 {
        return n as u64;
    }
    
    let mut a: u64 = 0;
    let mut b: u64 = 1;
    let mut temp: u64;
    
    for _i in 2..=n {
        temp = a + b;
        a = b;
        b = temp;
    }
    
    b
}

fn main() {
    fib_iterative(300);
}