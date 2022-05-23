use std::{env, fs};

fn print_help() -> i32 {
    let usage = fs::read_to_string("usage")
            .expect("Did you delete the usage file?");
    println!("{}", usage);
    return 1;
}

fn arg_count_gestion(args:&Vec<String>) -> i32 {
    if args.len() == 2 && args[1] == "-h" {
        return print_help()
    }
    if args.len() != 4 {
        return 84;
    }
    return 0;
}

fn parse_args() -> (u32, u32, f32) {
    let args: Vec<String> = env::args().collect();
    match arg_count_gestion(&args) {
        1 => std::process::exit(0),
        84 => {
            eprintln!("Argument error: wrong number of argument expected 3 got {}", args.len() - 1);
            std::process::exit(84);
        },
        _ => (),
    }
    let psize: u32 = match args[1].parse() {
        Ok(num) => num,
        Err(_) => {
            eprintln!("Argument error: wrong first argument expected a number superior or equal to 0 and got {}", args[1]);
            std::process::exit(84);
        },
    };
    let ssize: u32 = match args[2].parse() {
        Ok(num) => num,
        Err(_) => {
            eprintln!("Argument error: wrong second argument expected a number superior or equal to 0 and got {}", args[2]);
            std::process::exit(84);
        },
    };
    let p: f32 = match args[3].parse() {
        Ok(num) => num,
        Err(_) => {
            eprintln!("Argument error: wrong third argument expected a percentage and got {}", args[3]);
            std::process::exit(84);
        },
    };
    if ssize > psize {
        eprintln!("Argument error: sample size is bigger than population size {} > {}", args[2], args[1]);
        std::process::exit(84);
    }
    if p > 100.0 || p < 0.0 {
        eprintln!("Argument error: wrong third argument expected a percentage and got {}", args[3]);
        std::process::exit(84);
    }
    return (psize, ssize, p);
}

fn calculate_variance(psize:f32, ssize:f32, p:f32) -> f32 {
    return (p / ssize) * (1.0 - p) * ((psize - ssize)/(psize - 1.0))
}

fn main() {
    let (psize, ssize, p) = parse_args();
    println!("Population size:         {}", psize);
    println!("Sample size:             {}", ssize);
    println!("Voting intentions:       {:.2}%", p);
    let variance = calculate_variance(psize as f32, ssize as f32, p / 100.0);
    let standard_deviation = variance.sqrt();
    let confidence_dif_one = 1.96 * standard_deviation * 100.0;
    let confidence_dif_two = 2.58 * standard_deviation * 100.0;
    println!("Variance:                {:.6}", variance);
    println!("95% confidence interval: [{:.2}%; {:.2}%]", if (p - confidence_dif_one) < 0.0 { 0.0 } else {p - confidence_dif_one}, if p + confidence_dif_one > 100.0 { 100.0 } else { p + confidence_dif_one });
    println!("99% confidence interval: [{:.2}%; {:.2}%]", if (p - confidence_dif_two) < 0.0 { 0.0 } else {p - confidence_dif_two}, if p + confidence_dif_two > 100.0 { 100.0 } else { p + confidence_dif_two });
}
