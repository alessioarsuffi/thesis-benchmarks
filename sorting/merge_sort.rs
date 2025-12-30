struct SimpleRng {
    state: u64,
}

impl SimpleRng {
    fn new(seed: u64) -> Self {
        SimpleRng { state: seed }
    }
    
    fn next(&mut self) -> u32 {
        self.state = self.state.wrapping_mul(1103515245).wrapping_add(12345);
        (self.state >> 16) as u32
    }
    
    fn next_range(&mut self, max: u32) -> i32 {
        (self.next() % max) as i32
    }
}

fn merge(arr: &mut [i32], l: usize, m: usize, r: usize) {
    let n1 = m - l + 1;
    let n2 = r - m;
    
    let left: Vec<i32> = arr[l..=m].to_vec();
    let right: Vec<i32> = arr[m+1..=r].to_vec();
    
    let mut i = 0;
    let mut j = 0;
    let mut k = l;
    
    while i < n1 && j < n2 {
        if left[i] <= right[j] {
            arr[k] = left[i];
            i += 1;
        } else {
            arr[k] = right[j];
            j += 1;
        }
        k += 1;
    }
    
    while i < n1 {
        arr[k] = left[i];
        i += 1;
        k += 1;
    }
    
    while j < n2 {
        arr[k] = right[j];
        j += 1;
        k += 1;
    }
}

fn merge_sort(arr: &mut [i32], l: usize, r: usize) {
    if l < r {
        let m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

fn main() {
    let n = 1000000;
    let mut rng = SimpleRng::new(42);
    let mut arr: Vec<i32> = (0..n).map(|_| rng.next_range(1000000)).collect();
    
    merge_sort(&mut arr, 0, n - 1);
}