folder('Tools') {
    description("Folder for miscellaneous tools.")
}

job('Tools/clone-repository') {
    parameters{
        stringParam('GIT_REPOSITORY_URL', null, 'Git URL of the repository to clone')
    }
    wrappers {
        preBuildCleanup {
            includePattern('**/target/**')
            deleteDirectories()
            cleanupParameter('CLEANUP')
        }
    }
    steps {
        shell('git clone $GIT_REPOSITORY_URL')
    }
}

job('Tools/SEED') {
    parameters {
        stringParam('GITHUB_NAME', null, 'GitHub repository owner/repo_name (e.g.: "EpitechIT31000/chocolatine")')
        stringParam('DISPLAY_NAME', null, 'Display name for the job')
    }
    scm {
        github('\$GITHUB_NAME')
    }
    steps {
        dsl {
            text('''job ("\$DISPLAY_NAME") {
                wrappers {
                    preBuildCleanup {
                        includePattern('**/target/**')
                        deleteDirectories()
                        cleanupParameter('CLEANUP')
                    }
                trigger {
                    cron('*/1 * * * *')
                }
                steps {
                    shell("make fclean")
                    shell("make")
                    shell("make test")
                    shell("make clean")
                }
            }''')
        }
    }
}