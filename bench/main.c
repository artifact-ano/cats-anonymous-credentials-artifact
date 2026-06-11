#include <stdio.h>
#include <time.h>

#include "sep.h"
#include "osig.h"
#include "randombytes.h"
#include "random.h"

#include "bench_sep.h"
#include "bench_osig.h"
#include "bench_show.h"
#include "bench_hylac.h"

#define BENCH_ITERATIONS 10

int main(void) {
  arith_setup();
  random_init();

  printf("---------- Benchmarks (N = %d) -----------\n", BENCH_ITERATIONS);
  benchmark("SEP_KEYGEN", BENCH_ITERATIONS, sep_keygen_bench);
  benchmark("SEP_SIGN", BENCH_ITERATIONS, sep_sign_bench);
  benchmark("SEP_VERIFY (valid)", BENCH_ITERATIONS, sep_verify_valid_bench);
  benchmark("SEP_VERIFY (invalid)", BENCH_ITERATIONS, sep_verify_invalid_bench);
  printf("\n");
  benchmark("OSIG_USER_COMMIT", BENCH_ITERATIONS, osig_user_commit_bench);
  benchmark("OSIG_SIGNER_SIGN_COMMITMENT", BENCH_ITERATIONS, osig_signer_sign_commitment_bench);
  benchmark("OSIG_USER_SIGN_COMPLETE", BENCH_ITERATIONS, osig_user_sign_complete_bench);
  benchmark("OSIG_USER_VERIFY (valid)", BENCH_ITERATIONS, osig_user_verify_valid_bench);
  benchmark("OSIG_USER_VERIFY (invalid)", BENCH_ITERATIONS, osig_user_verify_invalid_bench);
  benchmark("OSIG_USER_KEYGEN", BENCH_ITERATIONS, osig_user_keygen_bench);
  benchmark("OSIG_USER_EMBED", BENCH_ITERATIONS, osig_user_embed_bench);
  benchmark("OSIG_USER_PROVE", BENCH_ITERATIONS, osig_user_prove_bench);
  benchmark("OSIG_SIGNER_VERIFY (valid)", BENCH_ITERATIONS, osig_signer_verify_valid_bench);
  benchmark("OSIG_SIGNER_VERIFY (invalid)", BENCH_ITERATIONS, osig_signer_verify_invalid_bench);
  printf("\n");
  benchmark("SHOW_USER_EMBED", BENCH_ITERATIONS, show_user_embed_bench);
  benchmark("SHOW_USER_PROVE", BENCH_ITERATIONS, show_user_prove_bench);
  benchmark("SHOW_USER_VERIFY (valid)", BENCH_ITERATIONS, show_user_verify_valid_bench);
  benchmark("SHOW_USER_VERIFY (invalid)", BENCH_ITERATIONS, show_user_verify_invalid_bench);
  printf("\n");
  benchmark("HYLAC_KEYGEN", BENCH_ITERATIONS, hylac_keygen_bench);
  benchmark("HYLAC_OSIG_USER_COMMIT", BENCH_ITERATIONS, hylac_osig_user_commit_bench);
  benchmark("HYLAC_OSIG_USER_PROVE", BENCH_ITERATIONS, hylac_osig_user_prove_bench);
  benchmark("HYLAC_OSIG_SIGNER_VERIFY (valid)", BENCH_ITERATIONS, hylac_osig_signer_verify_valid_bench);
  benchmark("HYLAC_ISSUE", BENCH_ITERATIONS, hylac_issue_bench);
  benchmark("HYLAC_ISSUED_CREDENTIAL_VERIFY", BENCH_ITERATIONS, hylac_issued_credential_verify_bench);
  benchmark("HYLAC_CDBDB_SHOW_USER_EMBED", BENCH_ITERATIONS, hylac_bridge_show_user_embed_bench);
  benchmark("HYLAC_CDBDB_SHOW_USER_PROVE", BENCH_ITERATIONS, hylac_bridge_show_user_prove_bench);
  benchmark("HYLAC_CDBDB_SHOW_USER_VERIFY (valid)", BENCH_ITERATIONS, hylac_bridge_show_user_verify_valid_bench);
  benchmark("HYLAC_CDBDB_SHOW_USER_VERIFY (invalid)", BENCH_ITERATIONS, hylac_bridge_show_user_verify_invalid_bench);
  benchmark("HYLAC_CDBDB_SHOW", BENCH_ITERATIONS, hylac_bridge_show_bench);
  benchmark("HYLAC_BULLETPROOF_RANGE_EMBED", BENCH_ITERATIONS, hylac_bp_range_embed_bench);
  benchmark("HYLAC_BULLETPROOF_RANGE_PROVE", BENCH_ITERATIONS, hylac_bp_range_prove_bench);
  benchmark("HYLAC_BULLETPROOF_RANGE_VERIFY (valid)", BENCH_ITERATIONS, hylac_bp_range_verify_valid_bench);
  benchmark("HYLAC_SHOW", BENCH_ITERATIONS, hylac_show_bench);
  benchmark("HYLAC_SHOW_VERIFY (valid)", BENCH_ITERATIONS, hylac_show_verify_valid_bench);

  printf("-------------------------------------------\n");

  arith_teardown();
  return 0;
}
