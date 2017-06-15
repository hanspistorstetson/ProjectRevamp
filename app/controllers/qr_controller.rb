class QrController < ApplicationController

  def new
    uuid = params[:qr][:uuid]
    @qrcode = RQRCode::QRCode.new(uuid, :size => 8, :level => :h)
  end

  def read

    redirect_to current_user
  end

end
