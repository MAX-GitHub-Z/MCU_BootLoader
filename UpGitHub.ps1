# 文件名：autoGitPush.ps1
Function gitPush {
    # 将脚本放置在项目根路径
    if ($PSVersionTable.PSVersion.Major -ge 3) {
        # PowerShell 3.0 或更高版本
        $ScriptPath = $PSCommandPath
    } else {
        # PowerShell 2.0 或更低版本
        $MyInvocation = (Get-Variable MyInvocation).Value
        $ScriptPath = $MyInvocation.MyCommand.Definition
        $ScriptDir = Split-Path -Parent $ScriptPath
    }

    $ScriptDir = Split-Path -Path $ScriptPath -Parent
    Write-Output $ScriptDir

    Set-Location $ScriptDir # 切换到项目路径
    $now = Get-Date # 获取时间日期对象
	$age = Read-Host -Prompt "输入提交信息"
    $msg = "==>当前时间 " + $now.ToString('yyyy-MM-dd HH:mm:ss') + " commit $age <=="# 提交的消息
    # 将提交信息输出到日志文件gitpush.log
    $msg | Out-File -FilePath .\gitpush.log -Append -Encoding utf8
    Write-Output $msg
	# 将代码的相关信息输出到日志文件gitpush.log
    git status >> .\gitpush.log 
    git add . >> .\gitpush.log
    git commit -m "$age"  >> .\gitpush.log
    git push origin master  >> .\gitpush.log
}

gitPush # 运行函数