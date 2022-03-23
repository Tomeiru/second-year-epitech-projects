folder('Tool') {
    description("Folder for miscellaneous tools.")
}

job('Tool/clone-repository') {
    parameters{
        stringParam('GIT_REPOSITORY_URL', null, 'Git URL of the repository to clone')
    }
    wrappers {
        preBuildCleanup { // Clean before build
            includePattern('**/target/**')
            deleteDirectories()
            cleanupParameter('CLEANUP')
        }
    }
    steps {
        shell('git clone $GIT_REPOSITORY_URL')
    }
}

job('Tool/SEED') {
    parameters {
        stringParam('GIT_NAME', null, 'GitHub repository owner/repo_name (e.g.: "EpitechIT31000/chocolatine")')
        stringParam('DISPLAY_NAME', null, 'Display name for the job')
    }
    wrappers {
        preBuildCleanup { // Clean before build
            includePattern('**/target/**')
            deleteDirectories()
            cleanupParameter('CLEANUP')
        }
    }
    scm {
        github('$GIT_NAME')
    }
    steps {
        job('$DISPLAY_NAME') {
            wrappers {
                preBuildCleanup { // Clean before build
                    includePattern('**/target/**')
                    deleteDirectories()
                    cleanupParameter('CLEANUP')
                }
            }
            steps {
                shell("make fclean")
                shell("make")
                shell("make test")
                shell("make clean")
            }
        }
    }
}