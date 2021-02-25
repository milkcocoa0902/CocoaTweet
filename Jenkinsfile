pipeline {
  agent {
    dockerfile true
  }

	stages{
		stage("parallel execution"){
			parallel{
				stage("doxygen"){
					steps{
						sh 'doxygen'
					}
				}

				stage("validation"){
					steps{
						sh 'tools/validate/includeGuard.sh'
					}
				}
				stage("build and test"){
					stages{
						stage("prepare"){
							steps{
								sh '''
									mkdir build
									cd $_
									cmake .. -G ninja
								'''
							}
						}

						stage("build"){
							steps{
								sh '''
									cd build ninja
								'''
							}
						}

						stage("test"){
							steps{
								echo "test"
							}
						}
					}
				}
			}
		}

		stage("upload artifact"){
			steps{
				archiveArtifacts allowEmptyArchive: true, artifacts: 'help/**/*.*', onlyIfSuccessful: true
			}
		}

	}
}
