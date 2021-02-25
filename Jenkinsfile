pipeline {
  agent {
    dockerfile true
  }

	stages{
	parallel{
		stage("doxygen"){
			steps{
				sh 'doxygen'
			}
		}

		stage("validation"){
			sh 'tools/validate/includeGuard.sh'
		}

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
				sh '''
					cd build ninja
				'''
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
